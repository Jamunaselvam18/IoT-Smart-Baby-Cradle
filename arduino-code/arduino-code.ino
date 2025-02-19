#include <Servo.h>
#include <SoftwareSerial.h>

// Create a servo object
Servo myservo;

// Pin definitions
int soundPin = A1;
int threshold = 400;
int servoPin = 9;
const int wetSensorPin = 4;
const int buzzerPin = 6; // Changed buzzer pin to 6

// SIM800L TX is connected to Arduino pin 2
#define SIM800_TX_PIN 2

// SIM800L RX is connected to Arduino pin 3
#define SIM800_RX_PIN 3

SoftwareSerial sim800l(SIM800_TX_PIN, SIM800_RX_PIN);

void setup() {
  // Initialize Serial
  Serial.begin(9600);
  
  // Attach the servo to the specified pin
  myservo.attach(servoPin);
  
  // Initialize SoftwareSerial for SIM800L communication
  sim800l.begin(9600);
  delay(1000);

  // Test if SIM800L is responding
  if (sendATCommand("AT")) {
    Serial.println("SIM800L is ready.");
  } else {
    Serial.println("SIM800L initialization failed. Check connections.");
    while (1);
  }

  delay(1000);

  // Set the sound pin as input
  pinMode(soundPin, INPUT);

  // Set the servo pin as output
  pinMode(servoPin, OUTPUT);

  // Set the wet sensor as an input
  pinMode(wetSensorPin, INPUT);

  // Set the buzzer as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the sound pin level
  int soundLevel = analogRead(soundPin);

  // If the sound level is above the threshold
  if (soundLevel > threshold) {
    // Move the servo to swing the cradle
    myservo.write(90);
    
    // Make a call
    makeCall("enter your phone number");

    // Wait for 30 seconds before making the next call
    //delay(30000);
    
    // Move the servo back to the middle position
    myservo.write(0);
  }

  // Read the value from the wet sensor
  int wetSensorValue = digitalRead(wetSensorPin);

  // If the wet sensor is triggered (i.e. wetness is detected)
  if (wetSensorValue != HIGH) {
    // Turn on the buzzer
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Turn off the buzzer
    digitalWrite(buzzerPin, LOW);
  }

  // Wait for a short period of time before checking the wet sensor again
  delay(100);
}

bool sendATCommand(String command) {
  sim800l.println(command);
  delay(500);
  
  while (sim800l.available()) {
    if (sim800l.find("OK")) {
      return true;
    }
  }
  
  return false;
}

void makeCall(String phoneNumber) {
  // AT command to make a call
  sim800l.print("ATD");
  sim800l.print(phoneNumber);
  sim800l.println(";");

  delay(1000); // Wait for the call to be initiated
}
