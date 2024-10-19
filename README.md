# Home Security System

## Project Overview
This project is a proof-of-concept home security system designed for university students, offering a low-cost and user-friendly solution. The system is composed of three primary components:
1. **Camera Subsystem** – Provides facial detection to monitor the front door.
2. **Package Lockbox Subsystem** – A secure, smart lockbox for package deliveries.
3. **Mobile Application** – Allows users to interact with both the camera and lockbox through a user-friendly interface.

Due to limited time and team size, the system was designed as a proof of concept and not a fully deployable product.

## Components

### 1. **Camera Subsystem**
- **Hardware**: Initially, an ESP32-CAM was chosen, but later replaced by a 720p webcam due to performance issues.
- **Software**: Facial detection and identity verification are performed using the **Deepface** library with image processing managed by **OpenCV**.

### 2. **Package Lockbox Subsystem**
- **Hardware**: Built with a solenoid lock, keypad, PIR sensor, and IR sensor. The lockbox was designed to accommodate varying package sizes.
- **Software**: Controlled by an Arduino, with code that integrates the sensors and manages the lock system. The keypad provides access by verifying pre-set codes.
  
### 3. **Mobile Application**
- **Frontend**: Developed using **Python** and the **Kivy framework**, the app provides the user with an intuitive interface to monitor packages and view camera footage.
- **Backend**: Not fully integrated but designed to be compatible with future development. 

## Features
- **Facial Detection**: Detects individuals at the front door and stores information.
- **Package Security**: Detects when a package is delivered and secures it in the lockbox.
- **App Integration**: Displays delivery information and allows access control to the lockbox and camera.

## Installation and Usage

### Prerequisites
- Python 3.8 or later
- Kivy Framework (`pip install kivy`)
- OpenCV (`pip install opencv-python`)
- Deepface (`pip install deepface`)

### Arduino Setup for Lockbox
Connect the hardware components (PIR sensor, IR sensor, solenoid lock, and keypad) according to the wiring diagram.
Upload the lockbox.ino code found in the arduino/ directory to your Arduino board.

## Design Considerations
- Cost: A major consideration was keeping costs low to accommodate student budgets.
- Power Efficiency: The design uses low-power components to minimize utility costs.
- Ease of Use: The app's user interface was designed with simplicity in mind to ensure accessibility.

## Future Recommendations
- Enhanced Camera: A higher resolution camera should be used for better facial recognition performance.
- Backend Integration: The app should be connected to both the camera and lockbox for a fully functional system.
- Weather Protection: The lockbox should be designed to withstand outdoor conditions.
