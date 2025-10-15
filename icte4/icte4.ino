#include "soc/gpio_reg.h"
#include "soc/soc.h"
#include "esp32/rom/ets_sys.h"

#define LED1 2
#define LED2 4
#define POT_PIN 34

// Bitmasks
#define LED1_MASK (1ULL << LED1)
#define LED2_MASK (1ULL << LED2)

// Task intervals (microseconds)
const unsigned long intervalLED1 = 500000;  // 0.5s
const unsigned long intervalLED2 = 1000000; // 1s
const unsigned long intervalPOT  = 200000;  // 0.2s

unsigned long prevLED1 = 0;
unsigned long prevLED2 = 0;
unsigned long prevPOT  = 0;

// States
bool led1State = false;
bool led2State = false;

void setup() {
  Serial.begin(115200);

  // Configure GPIOs as output (set bits in GPIO_ENABLE_REG)
  REG_WRITE(GPIO_ENABLE_W1TS_REG, LED1_MASK | LED2_MASK);
}

void loop() {
  unsigned long now = micros();

  // Task 1: Toggle LED1
  if (now - prevLED1 >= intervalLED1) {
    prevLED1 = now;
    led1State = !led1State;
    if (led1State)
      REG_WRITE(GPIO_OUT_W1TS_REG, LED1_MASK); // Set
    else
      REG_WRITE(GPIO_OUT_W1TC_REG, LED1_MASK); // Clear
  }

  // Task 2: Toggle LED2
  if (now - prevLED2 >= intervalLED2) {
    prevLED2 = now;
    led2State = !led2State;
    if (led2State)
      REG_WRITE(GPIO_OUT_W1TS_REG, LED2_MASK);
    else
      REG_WRITE(GPIO_OUT_W1TC_REG, LED2_MASK);
  }

  // Task 3: Potentiometer read
  if (now - prevPOT >= intervalPOT) {
    prevPOT = now;
    int potValue = analogRead(POT_PIN);
    Serial.print("Potentiometer: ");
    Serial.println(potValue);
  }
}