#ifndef __DEBOUNCER_H
#define __DEBOUNCER_H

#include "utils.h"
#include <stdint.h>

/// @brief Initialize the debouncer
/// @param ival_ms Interval in millis between each debounce check
/// @param pclk Peripheral clock frequency in MHz
/// @param int_priority Debouncer interrupt priority (0 (highest), 15 (lowest)). If NULL, the default priority is set.
void RIT_Init(u32 ival_ms, u32 pclk_mhz, _NULLABLE u16 *const int_priority);

void RIT_Enable(void);
void RIT_Disable(void);
void RIT_Reset(void);

_INT_HANDLER RIT_IRQHandler(void);

#endif