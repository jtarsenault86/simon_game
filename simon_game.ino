/*
DESCRIPTION: This is a "Simon" clone powered by the Arduino Uno. 
Version 1.1 06/02/26

-- See README for further details and explanations

Updates
-- Skeleton code for now

*/

// Constants and global variables
// pin for PWM to passive buzzer
const int BUZZER_PIN = 3;

// pins for external output
const int YELLOW_BUTTON_PIN = 4;
const int RED_BUTTON_PIN = 5;
const int GREEN_BUTTON_PIN = 6;
const int BLUE_BUTTON_PIN = 7;

// pins for LED output
const int YELLOW_LED_PIN = 10;
const int RED_LED_PIN = 11;
const int GREEN_LED_PIN = 12;
const int BLUE_LED_PIN = 13;

// tones for colors in Hz
const int GREEN_TONE = 415;
const int RED_TONE = 310;
const int YELLOW_TONE = 252;
const int BLUE_TONE = 209;

// arrays for level sequences, each level doubles in length 
int level_one[1] = {0};
int level_two[2] = {0};
int level_three[4] = {0};
int level_four[8] = {0};
int level_five[16] = {0};

// arrays for player guesses for each level
int guess_one[1] = {0};
int guess_two[2] = {0};
int guess_three[4] = {0};
int guess_four[8] = {0};
int guess_five[16] = {0};

/* Game component function prototypes*/
void generateArray(int arr[]);
void playLevelSounds(int arr[]);
void playerInput(int level, int arr[], int guess[]);
void playLevelPassed();
void playGameWon();
void playWrongInput();
void runGameLoop();

// the setup function runs once when you press reset or power the board
void setup() {

  // initalize serial port to however many baud you feel like, gosh!
  Serial.begin(9600); 
  Serial.write("\nSerial port initialized!\n");
  
  // initialize output pins
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

  // initialize input pins
  pinMode(RED_BUTTON_PIN, INPUT); 
  pinMode(GREEN_BUTTON_PIN, INPUT);
  pinMode(BLUE_BUTTON_PIN, INPUT);
  pinMode(YELLOW_BUTTON_PIN, INPUT);

  // initialize buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.write("\nInput and output pins initalized!\r");

  // seed random number generator
  randomSeed(analogRead(1));
  Serial.write("\nRandom number generator seeded!");
}

// main loop
void loop() {
  runGameLoop();
}


/* Game component functions */

// generate array of n-length pseudorandom numbers
void generateArray(int arr[]) {
  
}

// play sounds associated with a generated level
void playLevelSounds(int arr[]) {
  
}

// accept player input and check
void playerInput(int level, int arr[], int guess[]) {
  
}

// melodies for "level passed", "game won", and "wrong input"
void playLevelPassed() {
  
}

void playGameWon() {
  
}

void playWrongInput() {
  
}

// main game loop

void runGameLoop() {
  Serial.write("\ngame loop starting\r");
}
