# Pacer: Autonomous Rover with Computer Vision

Welcome to the Pacer project repository! Pacer is an autonomous rover equipped with cutting-edge computer vision capabilities, powered by Google's Vision Transformer (ViT) model. This project aims to enhance environmental monitoring and disaster response efforts by leveraging AI-driven technology to detect smoke and fire in real-time.

## Key Features
- **Navigation:** Pacer utilizes advanced navigation algorithms to traverse various terrains and environments on predefined path.
- **Computer Vision:** The rover is equipped with Google's Vision Transformer (ViT) model, enabling it to detect smoke and fire with high accuracy and efficiency.
- **Automated Email System:** Upon detecting smoke or fire, Pacer automatically sends email alerts to designated recipients, facilitating rapid response and mitigation efforts.
  
navigation on this predefined path:

![image](https://github.com/hassantfaily/Pacer/assets/132168189/32990902-f0a9-4c5e-8c7d-bcb9ad272389)

## Getting Started
1. Clone the repository to your local machine.
2. Install the necessary dependencies and libraries specified in the `requirements.txt` file.
3. Configure the email settings and recipient list in the email automation module.
4. uplaod the C++ code into your mcore baord.
5. upload the python scripts onto your rasberryPi.
6. configure your Pi camera.
7. Run the main script and keep the email script contiously running.

Sample email message:
![image](https://github.com/hassantfaily/Pacer/assets/132168189/9223bf85-276e-4ae3-82fc-8758d888ef3e)

results for our ViTransformer:
Accuracy = 89.94%
Precision = 88.3%
Recall = 92.22%
F1 score = 0.9

## Contributing
We welcome contributions from the open-source community to enhance and expand the capabilities of the Pacer project. Feel free to submit pull requests, report issues, or suggest new features to help drive innovation in environmental monitoring technology.

## License
This project is licensed under the [MIT License](LICENSE), allowing for free use, modification, and distribution of the software.
