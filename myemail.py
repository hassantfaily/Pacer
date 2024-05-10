import os
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.image import MIMEImage

def send_email():
    sender_email = 'pacer.emergency@outlook.com'
    receiver_email = 'charbel.boutros01@lau.edu'
    password = 'Bozo1500$?1200$?idc,just$'

    desktop_path = os.path.expanduser("~/Desktop")
    target_picture_path = os.path.join(desktop_path, "target.jpg")

    if not os.path.isfile(target_picture_path):
        print("No 'target.jpg' found on the desktop. Email not sent.")
        return

    msg = MIMEMultipart()
    msg['From'] = sender_email
    msg['To'] = receiver_email
    msg['Subject'] = 'ALERT!!'

    body = 'Here is the attached image.'
    msg.attach(MIMEText(body, 'plain'))

    with open(target_picture_path, 'rb') as attachment:
        img = MIMEImage(attachment.read(), name=os.path.basename(target_picture_path))
    msg.attach(img)

    # Send email
    with smtplib.SMTP('smtp-mail.outlook.com', 587) as server:
        server.starttls()
        server.login(sender_email, password)
        server.send_message(msg)

    print("Email sent successfully.")

# Send email if there's a picture named "target.jpg" on the desktop
send_email()
