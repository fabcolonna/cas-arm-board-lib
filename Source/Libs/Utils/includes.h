#ifndef __INCLUDES_H
#define __INLCUDES_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "buttons.h"
#include "debouncer.h"
#include "led.h"
#include "power.h"
#include "timer.h"

// Set this to true to use the RIT interrupt for button debouncing,
// or false to use the normal EINTx interrupts in the buttons library.
#define USE_RIT_DEBOUNCE true

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // Needs to be visible in order to become visible by the simulator
#endif

#endif