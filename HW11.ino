
const int potPin = A0; 
const int buttonPin = 2; 
const int lightSensorPin = A1; 
const int ledPinSuccess = 4; 
const int ledPinFail = 5; 

int potValue = 0; 
int buttonState = 0; 
int lightSensorValue = 0; 
int stepCount = 0; 

void setup() {

  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(lightSensorPin, INPUT);
  pinMode(ledPinSuccess, OUTPUT);
  pinMode(ledPinFail, OUTPUT);

 
  Serial.begin(9600);
}

void loop() {

  potValue = analogRead(potPin);

  buttonState = digitalRead(buttonPin);

  lightSensorValue = analogRead(lightSensorPin);


  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  Serial.print("Light Sensor Value: ");
  Serial.println(lightSensorValue);


  if (buttonState == LOW) {
   
    if (potValue > 2000 && lightSensorValue < 50) { 
      stepCount++; 
      if (stepCount >= 3) { 
        digitalWrite(ledPinSuccess, HIGH);
        digitalWrite(ledPinFail, LOW);
      }
    } else {
      digitalWrite(ledPinFail, HIGH); 
      digitalWrite(ledPinSuccess, LOW); 
      stepCount = 0; 
    }
    delay(1000); 
  }

  delay(100);
}