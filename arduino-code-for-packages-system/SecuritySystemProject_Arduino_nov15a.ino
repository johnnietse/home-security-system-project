#include <Keypad.h> //import keypad library 

const int RELAY_PIN  = A5; // the Arduino pin, which connects to the IN pin of relay for relay control.
const int ROW_NUM    = 4; // Number of rows in the keypad: 4 rows
const int irSensor = 2; // Infrared sensor pin

int pirPin = 3; // PIR (Passive Infrared) sensor pin
int pirState = LOW; // PIR sensor state
int pirValue = 0; // PIR sensor value


const int COLUMN_NUM = 4; // Number of columns in the keypad: 4 columns

// Define the keypad layout
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

// Define the row and column pins for the keypad
byte pin_rows[ROW_NUM] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

const String password_1 = "1234ABC"; // Define password 1
const String password_2 = "5642AB";  // Define password 2
const String password_3 = "4545A";   // Define password 3
String input_password;

void setup() {
  Serial.begin(9600);
  input_password.reserve(32); // // Reserve space for input password, maximum input characters is 33, change if needed
  pinMode(RELAY_PIN, OUTPUT); // initialize relay pin as an output.
  digitalWrite(RELAY_PIN, LOW); // Initially, lock the lockbox with the solenoid lock if there is no one around the system
  pinMode(pirPin, INPUT); // Set PIR sensor pin as input
  

}

void loop() {
  
  char key = keypad.getKey(); // Get key from the keypad

  int irValue = digitalRead(irSensor); // Read value from the infrared sensor

  int pirValue = digitalRead(pirPin); // Read value from the PIR sensor




  static bool printed1 = false; // Flag to ensure printing only once


  // Check PIR sensor for motion detection
  if (irValue == HIGH && !printed1) {// check if the input is HIGH
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
      printed1 = true;
    }
  } 
  
  else {
    if (pirState == HIGH && !printed1){
      // we have just turned off
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
      printed1 = true;
    }
  }



  // Flag to ensure printing only once
  static bool printed2 = false;

  // Check infrared sensor for object detection --> to check whether the parcel is there or not
  if(irValue == 1 && !printed2){
    Serial.print("irSensorValue: ");
    Serial.println(irValue);
  
    Serial.println("Object detected!");

    printed2 = true;

  }

      
  if (key){

    
    Serial.println(key);
    

    if(key == '*') {
      input_password = ""; // reset the input password
    } 
    
    else if(key == '#') {
      if(input_password == password_1 || input_password == password_2 || input_password == password_3) {
        // Check entered password and unlock the solenoid lock if correct
        Serial.println("The password is correct, unlocking the door for 20 seconds");
        digitalWrite(RELAY_PIN, HIGH);  // unlock the lock for 20 seconds
        delay(20000);
        digitalWrite(RELAY_PIN, LOW); // lock the lock
        Serial.println("The lock is locked now.");
      } 
      
      else {
        Serial.println("The password is incorrect, try again");
      }

      input_password = ""; // reset the input password
    } 
    
    else {
      input_password += key; // append new character to input password string
    }
  }
}
