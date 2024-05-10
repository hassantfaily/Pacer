from PIL import Image
from transformers import AutoImageProcessor, AutoModelForImageClassification
import torch

class MyModel: 
    def __init__(self):
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        print(f"Using device: {self.device}")

        # Load processor and model on the appropriate device
        self.processor = AutoImageProcessor.from_pretrained("vit-fire-detection")
        self.model = AutoModelForImageClassification.from_pretrained("vit-fire-detection").to(self.device)

    def predict(self, image_path):
        # Load and preprocess image
        image = Image.open(image_path)
        inputs = self.processor(image, return_tensors="pt").to(self.device)
                        
        # Perform inference
        outputs = self.model(**inputs)
                        
        # Get predicted probabilities
        predicted_probabilities = outputs.logits.softmax(dim=-1)
        positive_probability = predicted_probabilities[0][1].item()  # Probability of positive class
        negative_probability = predicted_probabilities[0][0].item()  # Probability of negative class

        # Determine predicted class based on probabilities
        predicted_class = "No fire" if positive_probability > negative_probability else "Fire"
        
        return predicted_class,negative_probability

# Example usage
