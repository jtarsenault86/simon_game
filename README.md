# simon_game
Game: "Simon" clone for the Arduino Uno

## Description
<p>This is a port of single player Simon for the Arduino Uno or equivalent MCU.</p>
<p>It is constructed using basic components from an Arduino starter kit. A 10 kOhm rotary potentiometer is used for difficulty level selection.</p>
<p>Note: This is very much a work in progress. As I obtain more and better components, I will improve and expand the functionality of the game ...</p>


<p>Folder contents:</p>

	1. An Arduino sketch (.ino file)
	2. audio.cpp
	3. audio.h
	4. timer.h
	5. tone_freq.h


<p>The .ino file can be uploaded to the Arduino through the Arduino IDE. All files are required to run the game.<br>Note: Due to the Arduino IDE's naming conventions, the folder name must match the name of the .ino file. Keep in mind when modifying files.</p>

## Note on Wiring and Assembly
<p>Soon I will include a detailed schematic. For now, the relevant GPIO pins are indicated in the code.</p>
<p>The LED outputs have 560 Ohm resistors. The player input consists of four momentary switches, each with a 10 kOhm pull-up resistor.</p>


## How to Play

<p>For those who don't already know, Simon is simple memory game first released by Milton Bradley in 1978. The computer generates an increasingly long sequence of sounds which the player must correctly repeat back. If too much time passes (5 seconds per sound), or if the player makes one wrong guess, the game is over. Like the original, this game has four levels:

	1. Level 1 - 8 tones
	2. Level 2 - 14 tones
	3. Level 3 - 20 tones
	4. Level 4 - 31 tones

After startup, the player has 30 seconds to choose a level indicated by the following LEDs before the game begins<br>

	1. Level 1 - Blue
	2. Level 2 - Yellow
	3. Level 3 - Red
	4. Level 4 - Green

Completing a sequence of maximum length twice wins.
</p>


## Additional Details

<p>I've included a module of basic melodies and a header file of musical tone frequencies (melodies.cpp, melodies.h, tone_freq.h) to easily enable changing of the game's tones. The defaults are E, C-Sharp, A, E.  A common alternative is B-Flat, D-Flat, F, B-Flat.</p>
<p>The serial monitor is used for debugging purposes.</p>
<p>There are some basic test functions at the bottom of the .ino file for testing the basic functionality of the setup. Later, I will move this to its own module.</p>
