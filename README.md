# ESP32 Buzzer Annoyer (For Fun)

This project lets anyone on the internet trigger a buzzer connected to your ESP32 — just to annoy you (or have fun with your friends).

This is a fun and simple project built using:
- An **ESP32**
- A **passive buzzer**
- A **Firebase backend**
- A pre-built **Android app**
- A ready-to-deploy **website interface**

## How Does It Works?

1. The ESP32 checks a Firebase Realtime Database every second.
2. If a button press is detected (from the website or app), the buzzer beeps for **1 second**.
3. The cycle continues endlessly as long as the ESP32 is powered.

The goal? To give others the ability to trigger your buzzer anytime, anywhere!

## Features

- Real-time buzzing via Firebase
- Pre-built website for easy interaction
- Android app that notifies the user when the beep has been successfully triggered

## Hardware Requirements

- ESP32 (tested on **DOIT ESP32 DEVKIT V1**)
- Passive buzzer
- Any **reliable power source**

### Wiring

- **Buzzer GND** → **ESP32 GND**
- **Buzzer VCC** → **ESP32 GPIO 5**

## Setup Guide

### 1. Firebase Setup
- Create a new Firebase project
- Add a **Web App**
- Enable:
  - **Firebase Authentication**
  - **Firebase Realtime Database**
- Get your Firebase config info

### 2. ESP32 Firmware
- Open the Arduino project in the repo
- Replace the placeholder Firebase and WiFi credentials with your own
- Select board: `DOIT ESP32 DEVKIT V1`
- Upload the code to your ESP32

### 3. Website
- Provided in the repo (`web` folder)
- Insert your Firebase config into the JS file
- Host it anywhere (Firebase Hosting recommended)

### 4. Android App (Optional)
- Provided in the repo (`android` folder)
- Add your Firebase config
- Build the APK and install it
- The app will notify the user when the beep has been received by the ESP32

## Important Notes

- **Security Warning**: The Firebase setup is intentionally simple for fun. Do **not** expose this project publicly unless you secure your database rules.
- **Recommended Use**: With friends or on local networks.
- **Customization**: You can easily change the GPIO pin, delay time, or Firebase paths.

## License

This project is open-source and intended for educational and entertainment purposes only. Use responsibly.