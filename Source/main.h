#ifndef __BASE_H
#define __BASE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "buttons.h"
#include "debouncer.h"
#include "led.h"
#include "power.h"
#include "timer.h"

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // Needs to be visible in order to become visible by the simulator
#endif

#endif