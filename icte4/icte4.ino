// Filename: icte4.ino
// Authors: Sam Mansouri and Matthew Calim
// Date: 10/15/2025
// Description: This code blinks two LEDs at different rates and reads a potentiometer value every 100ms.

// ===== Constants =====
const int LED1 = 19; // first LED
const int LED2 = 18; // other led
const int POTENT_PIN = 4; // potentiometer signal

// need to set the time periods 
const unsigned long time_LED1 = 200;
const unsigned long time_LED2 = 750;
const unsigned long time_POTENT = 100;

// ===== Global Variables =====
// need to store the last timestamp, keep track of when the led last blinked and when pot last printed
unsigned long t1 = 0, t2 = 0, tp = 0;

// keep track of LEDs current state (on or off)
bool s1 = false, s2 = false;

void setup() {

  pinMode(LED1, OUTPUT); // setting outputs
  pinMode(LED2, OUTPUT); // setting output
  digitalWrite(LED1, LOW); // initial set to low
  digitalWrite(LED2, LOW); // intiial set to low

  Serial.begin(115200);

}

void loop() {

  unsigned long now = millis(); // timestamp per pass (recommended by gpt)

  if (now - t1 >= time_LED1) { // checking that 200ms have passed
    s1 = !s1; // togglging the state, flip it
    digitalWrite(LED1, s1); // updating the LED state
    t1 = now;  // this is the new toggle time reference
  }

  if (now - t2 >= time_LED2) { // checking that 750ms have passed
    s2 = !s2; // togglging the state, flip it
    digitalWrite(LED2, s2); // updating the LED state
    t2 = now;  // this is the new toggle time reference
  }

  if (now - tp >= time_POTENT) { // checking that 200ms have passed
    int raw = analogRead(POTENT_PIN); // pulling 0-4095 value
    Serial.print("Potentiometer reading: ");
    Serial.println(raw);
    tp = now;  // this is the new toggle time reference
  }

}