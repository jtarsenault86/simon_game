/* Header file of timer-related constants */

#ifndef TIMER_H
#define TIMER_H

// Timer related globals
// Time since unit startup in milliseconds and then microseconds
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


#endif
