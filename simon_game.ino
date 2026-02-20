/*  This is a test version of a "Simon" game for the Arduino Uno
 *  A 10 kOhm rotentiary potentiometer is used to select difficulty level.
 *  Input buttons use pull-up resistors.
 *  
 *  Last updated: 19/02/26
 */

// Includes for timer constants and functions and constants for playing tones with the 
// piezo-transducer (buzzer).
#include "melodies.h"
#include "timer.h"
#include "tone_freq.h"

// Output pin number constants
#define BUZZER_PIN     3
#define GREEN_LED_PIN  10
#define RED_LED_PIN    11
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN   13

// Input pin number constants
const int POT_INPUT = A0;
#define BLUE_BUTTON_PIN    4
#define YELLOW_BUTTON_PIN  5
#define RED_BUTTON_PIN     6
#define GREEN_BUTTON_PIN   7

// Color tone frequencies
#define BLUE_TONE TONE_G3



// Timer related globals
// Time since unit startup in milliseconds and then microseconds
// TODO: It is most likely prudent to move all these constants into a 
// seperate timer.h header at some future point
unsigned long currentTimeMs = 0;
unsigned long currentTimeUs = 0;

// Defined intervals: answer time short (20s), answer time long (45s);
// menu select time (30s)
const unsigned long answerIntervalShortMs = 20000;
const unsigned long answerIntervalLongMs  = 45000;
const unsigned long menuIntervalMs        = 30000;

const unsigned long answerIntervalShortUs = 20000000;
const unsigned long answerIntervalLongUs  = 45000000;
const unsigned long menuIntervalUs        = 30000000;


// Function prototypes:



void runOutputTests();
void runInputTests();

// Set pin modes and start serial port
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  pinMode(POT_INPUT, INPUT);
  pinMode(GREEN_BUTTON_PIN, INPUT_PULLUP); 
  pinMode(RED_BUTTON_PIN, INPUT_PULLUP);
  pinMode(YELLOW_BUTTON_PIN, INPUT_PULLUP);
  pinMode(BLUE_BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(115200);
  Serial.write("Serial port initalized\n");
  
  runOutputTests();
  runInputTests();
}

void loop() {
  

}



/* Test Functions */

void runInputTests() {

  Serial.write("Input tests\n");
  // Test blue button
  if (digitalRead(BLUE_BUTTON_PIN) == LOW) {
    Serial.write("Blue button pressed\n");
    digitalWrite(BLUE_LED_PIN, HIGH);
    tone(BUZZER_PIN, BLUE_TONE);
    delay(500);
    noTone(BUZZER_PIN);
    digitalWrite(BLUE_LED_PIN, LOW);
  }
  
  // Test yellow button

  // Test red button

  // Test green button
  
}

void runOutputTests() {

  Serial.write("Testing buzzer\n");
  tone(BUZZER_PIN, TONE_C4);
  delay(250);
  noTone(BUZZER_PIN);
  delay(50);
  tone(BUZZER_PIN, TONE_C4);
  delay(250);
  noTone(BUZZER_PIN);
  delay(50);

  Serial.write("Testing LEDs\n");
  digitalWrite(BLUE_LED_PIN, HIGH);
  delay(250);
  digitalWrite(YELLOW_LED_PIN, HIGH);
  delay(250);
  digitalWrite(RED_LED_PIN, HIGH);
  delay(250);
  digitalWrite(GREEN_LED_PIN, HIGH);
  delay(500);
  
  digitalWrite(GREEN_LED_PIN, LOW);
  delay(250);
  digitalWrite(RED_LED_PIN, LOW);
  delay(250);
  digitalWrite(YELLOW_LED_PIN, LOW);
  delay(250);  
  digitalWrite(BLUE_LED_PIN, LOW);
  
}
