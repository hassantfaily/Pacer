import RPi.GPIO as GPIO
from picamera import PiCamera
import time
from datetime import datetime
import shutil
import os
import cv2   
import numpy as np  
from test2 import MyModel

camera = PiCamera()
sensor_pin = 9 
GPIO.setmode(GPIO.BCM) 
GPIO.setup(sensor_pin, GPIO.IN)  
def capture_image(image_folder,counter):
    camera.start_preview()
    time.sleep(1) 
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    image_name = f'{counter}.jpg'
    image_path = os.path.join(image_folder, image_name)
    camera.capture(image_path)
    print(f"Image captured successfully and saved as {image_path}")
    camera.stop_preview()

def evaluate_images(image_folder):
    accuracy_dict = {}
    model = MyModel()  
    for filename in os.listdir(image_folder):
        if filename.endswith(".jpg"):  
            image_path = os.path.join(image_folder, filename)
            image = cv2.imread(image_path)
            rescaled_image = cv2.resize(image, (224, 224))
            classq,accuracy = model.predict(rescaled_image)
            filename_without_extension = os.path.splitext(filename)[0]
            accuracy_dict[filename_without_extension] = accuracy

    return accuracy_dict

def which_img(accuracies):
    # Filter (accuracy >= 0.3)
    filtered_accuracies = {filename: accuracy for filename, accuracy in accuracies.items() if accuracy >= 0.3}
    sorted_accuracies = sorted(filtered_accuracies.items(), key=lambda x: x[1], reverse=True)
    top_filenames = [filename for filename, _ in sorted_accuracies[:3]]
    return ''.join([filename for filename in top_filenames])


def copy_and_delete_image(chris_folder, target_folder, image_name):
    
    source_path = os.path.join(chris_folder, image_name)
    target_path = os.path.join(target_folder, 'target.jpg')
    shutil.copy(source_path, target_path)
    print(f"Image {image_name} copied to desktop as target.jpg")

    time.sleep(600)  # 10 minutes
    os.remove(target_path)
    print("Image deleted from desktop")

if __name__ == "__main__":
    source_folder = 'Users\User\Desktop\msd project\pi_pic'
    image_count = 0

    try:
        while True:
            if GPIO.input(sensor_pin) == GPIO.HIGH:
                capture_image(source_folder,image_count)
                image_count += 1
                # Check if folder contains 5 pictures
                if image_count >= 5:
                    accuracies = evaluate_images(source_folder)
                    # Define the name of the image to be copied
                    image_name = which_img(accuracies)
                    # Define the target folder (desktop)
                    desktop_folder = os.path.expanduser("~/Desktop")
                    chris_folder='Users\User\Desktop\msd project\chris_folder'
                    # Call the function to copy and delete the image
                    copy_and_delete_image(chris_folder, desktop_folder, f"{image_name}.jpg")
                    for filename in os.listdir(source_folder):
                         if filename.endswith(".jpg"):
                            file_path = os.path.join(source_folder, filename)
                            os.remove(file_path)
                            print(f"Removed {file_path}")
                    image_count = 0 
                time.sleep(2) 
    except KeyboardInterrupt:
        print("Exiting program")
    finally:
        GPIO.cleanup()
