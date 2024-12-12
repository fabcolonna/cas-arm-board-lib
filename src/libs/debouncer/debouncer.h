#ifndef __DEBOUNCER_H
#define __DEBOUNCER_H

#include "utils.h"
#include <stdint.h>

/// @brief Initialize the debouncer
/// @param ival_ms Interval in millis between each debounce check
/// @param pclk Peripheral clock frequency in MHz
void RIT_Init(u32 ival_ms, u32 pclk_mhz);

void RIT_Enable(void);
void RIT_Disable(void);
void RIT_Reset(void);

_INT_HANDLER RIT_IRQHandler(void);

#endif