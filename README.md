# IoT-Based Smart Baby Cradle

## Overview
This project is an IoT-based solution designed for remote infant monitoring. It enhances parental peace of mind and reduces risks by integrating real-time data collection and analysis using Arduino and Python.

### Features
- **Real-Time Monitoring:** Tracks sound levels, temperature, and pulse rates.
- **Audio Analysis:** Identifies specific infant sounds (e.g., crying) using a trained machine learning model.
- **IoT Integration:** Uses Arduino and sensors for data acquisition and communication.

---

## Repository Structure
```
/arduino-code/ # Contains the Arduino IDE code for sensor integration
/python-audio-model/ # Contains the Python script for audio/sound training
```

---

## Technologies Used
- **Arduino IDE**: For writing and uploading code to the Arduino microcontroller.
- **Python**: For training a machine learning model to analyze infant sounds.
- **Sensors**: Includes sound, temperature, moisture sensor and pulse rate sensors.

---

## How to Run
### Arduino Code:
1. Open the `arduino-code` folder.
2. Load the `.ino` file in Arduino IDE.
3. Connect your Arduino board and upload the code.

### Python Code:
1. Navigate to the `python-audio-model` folder.
2. Install required Python dependencies:
   ```bash
   pip install -r requirements.txt
   ```
3. Run the Python script for audio analysis:
   ```bash
   python train_audio_model.py
   ```

---

## Future Improvements
- Add more advanced AI features for better sound analysis.
- Include a mobile app for real-time alerts and monitoring.
- Expand the range of monitored parameters.

---




