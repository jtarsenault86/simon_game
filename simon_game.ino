/*  This is a test version of a "Simon" game for the Arduino Uno
 *  A 10 kOhm rotentiary potentiometer is used to select difficulty level.
 *  Input buttons use pull-up resistors.
 *  
 *  Last updated: 21/02/26
 */

// Includes for timer constants and functions and constants for playing tones with the 
// piezo-transducer (buzzer).
#include "audio.h"
#include "timer.h"
#include "tone_freq.h"

// Color tone frequencies
#define BLUE_TONE   TONE_G3
#define YELLOW_TONE TONE_C4
#define RED_TONE    TONE_E4
#define GREEN_TONE  TONE_G4

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


// Arrays to hold generated sequences and player guesses for each level
int levelOne[8] = {0};
int levelTwo[14] = {0};
int levelThree[20] = {0};
int levelFour[31] = {0};

int guessOne[8] = {0};
int guessTwo[14] = {0};
int guessThree[20] = {0};
int guessFour[31] = {0};

const int levelOneLength = 8;
const int levelTwoLength = 14;
const int levelThreeLength = 20;
const int levelFourLength = 31;

// Function prototypes:

int readButtonPress();
int readPotInput();

void generateSequence(int level);

void playBack(int output);

void runGameLoop();
int runLevelSelect();

long timeNow = millis();

// Set pin modes, start serial port, seed RNG
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  pinMode(POT_INPUT, INPUT);
  pinMode(GREEN_BUTTON_PIN, INPUT); 
  pinMode(RED_BUTTON_PIN, INPUT);
  pinMode(YELLOW_BUTTON_PIN, INPUT);
  pinMode(BLUE_BUTTON_PIN, INPUT);

  Serial.begin(115200);
  Serial.write("Serial port initalized\n");

  randomSeed(A1);
  
}

void loop() {

  runGameLoop();
}

/* Wrapper functions */

// main game loop
void runGameLoop() {
  
  // TODO: level select - timer requires a wrapper func
  int gameLevel = runLevelSelect();
  delay(1000);
  
  // TODO: generate level
  generateSequence(gameLevel);
  
  // TODO: player input - timer also required
  
}

// Runs 20 second timer for level selection and returns level indicated.
int runLevelSelect() {
  Serial.write("Selecting Level ... \n");
  timeNow = millis();
  long prevTimeCheck = 0;
  const long selectTimeLimit = 20000;
  int levelSelection;

  while((timeNow - prevTimeCheck) <= selectTimeLimit) {
    Serial.write("Making Selection....\n");
    timeNow = millis();
    delay(1000);
    levelSelection = readPotInput();


  }
  
  Serial.write("Time's up!\n");
  return levelSelection;
  
}




/* Input functions */


// Process user input (1): push buttons
// polls for a single button to be pressed
// returns int correspoding to color/tone entered
int readButtonPress() {

  bool polling = true;

  while(polling) {

    const int debouncePeriod = 100;
    unsigned long lastPressTime = 0;
    
    if (!digitalRead(BLUE_BUTTON_PIN && (lastPressTime > timeNow + debouncePeriod))) {
      Serial.write("Blue button pressed\n");
      digitalWrite(BLUE_LED_PIN, HIGH);
      tone(BUZZER_PIN, BLUE_TONE);
      delay(500);
      noTone(BUZZER_PIN);
      digitalWrite(BLUE_LED_PIN, LOW);
      polling = false;
      return BLUE_BUTTON_PIN;
    }

    else if (!digitalRead(YELLOW_BUTTON_PIN) && (lastPressTime > timeNow + debouncePeriod)) {
      Serial.write("Yellow button pressed\n");
      digitalWrite(YELLOW_LED_PIN, HIGH);
      tone(BUZZER_PIN, YELLOW_TONE);
      delay(500);
      noTone(BUZZER_PIN);
      digitalWrite(YELLOW_LED_PIN, LOW);
      polling = false;
      return YELLOW_BUTTON_PIN;
    }

    else if (!digitalRead(RED_BUTTON_PIN) && (lastPressTime > timeNow + debouncePeriod)) {
      Serial.write("Red button pressed\n");
      digitalWrite(RED_LED_PIN, HIGH);
      tone(BUZZER_PIN, RED_TONE);
      delay(500);
      noTone(BUZZER_PIN);
      digitalWrite(RED_LED_PIN, LOW);
      polling = false;
      return RED_BUTTON_PIN;
    }

    else if (!digitalRead(GREEN_BUTTON_PIN) && (lastPressTime > timeNow + debouncePeriod)) {
      Serial.write("Green button pressed\n");
      digitalWrite(GREEN_LED_PIN, HIGH);
      tone(BUZZER_PIN, GREEN_TONE);
      delay(500);
      noTone(BUZZER_PIN);
      digitalWrite(GREEN_LED_PIN, LOW);
      polling = false;
      return GREEN_BUTTON_PIN;
    }
    else {
      Serial.write("Still waiting for choice...\n");    
    }
  }
}


// Process user input (2): potentiometer / level select
// returns int corresponding to level selected
int readPotInput() {

  int option = analogRead(POT_INPUT);

  if (option >= 0 && option < 256) {
    digitalWrite(BLUE_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    Serial.write("Level one selected\n");
    return 1;
  }

  else if (option >= 256 && option < 512) {
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    Serial.write("Level two selected\n");
    return 2;
  }

  else if (option >= 512 && option < 767) {
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    Serial.write("Level three selected\n");
    return 3;
  }

  else if (option >= 767 && option <= 1023) {
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    Serial.write("Level four selected\n");
    return 4;
  }

  // If an outside value occurs, display error message and blink LEDs
  // This shouldn't occur. If it does, it is most likely due to hardware/wiring issues.
  else {

    digitalWrite(BLUE_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, HIGH);
    delay(500);

    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    delay(500);

    // TODO: write "error" melody
  }
  
}




/* Sequence generation and management functions */

void generateSequence(int level) {

  switch (level) {
    case 1:
      Serial.write("Generating level one sequence\n");
      for(int i = 0; i < levelOneLength; i++) {
        levelOne[i] = random(0,4);
        Serial.print(levelOne[i]);
        Serial.write(" ");
        playBack(levelOne[i]);
      }
      Serial.write("\n");
      
      break;

    case 2:
      Serial.write("Generating level two sequence\n");
      for(int i = 0; i < levelTwoLength; i++) {
        levelOne[i] = random(0,4);
        Serial.print(levelTwo[i]);
        Serial.write(" ");
      }
      Serial.write("\n");      
      break;

    case 3:
      Serial.write("Generating level three sequence\n");
      for(int i = 0; i < levelThreeLength; i++) {
        levelOne[i] = random(0,4);
        Serial.print(levelOne[i]);
        Serial.write(" ");
      }
      Serial.write("\n");      
      break;

    case 4:
      Serial.write("Generating level four sequence\n");
      for(int i = 0; i < levelFourLength; i++) {
        levelOne[i] = random(0,4);
        Serial.print(levelOne[i]);
        Serial.write(" ");
      }
      Serial.write("\n");      
      break;

    default:
      Serial.write("Error: invalid level\n");
      break;
    
  }
}


/* 

/* Output functions */
void playBack(int output) {

  switch(output) {

     // blue
    case 0:
      digitalWrite(BLUE_LED_PIN, HIGH);
      tone(BUZZER_PIN, BLUE_TONE);
      delay(500);
      digitalWrite(BLUE_LED_PIN, LOW);
      noTone(BUZZER_PIN);
      delay(100);
      break;

    // yellow
    case 1:
      digitalWrite(YELLOW_LED_PIN, HIGH);
      tone(BUZZER_PIN, YELLOW_TONE);
      delay(500);
      digitalWrite(YELLOW_LED_PIN, LOW);
      noTone(BUZZER_PIN);
      delay(100);
      break;

    // red
    case 2:
      digitalWrite(RED_LED_PIN, HIGH);
      tone(BUZZER_PIN, RED_TONE);
      delay(500);
      digitalWrite(RED_LED_PIN, LOW);
      noTone(BUZZER_PIN);
      delay(100);
      break;

    // green
    case 3:
      digitalWrite(GREEN_LED_PIN, HIGH);
      tone(BUZZER_PIN, GREEN_TONE);
      delay(500);
      digitalWrite(GREEN_LED_PIN, LOW);
      noTone(BUZZER_PIN);
      delay(100);
      break;

    default:
      Serial.print("Error: Invalid input for sound\n");
      break;
  }

}
