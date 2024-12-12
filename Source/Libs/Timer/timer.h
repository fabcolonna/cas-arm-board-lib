#ifndef __TIMER_H
#define __TIMER_H

#include "timer_types.h"
#include "utils.h"
#include <stdint.h>

/// @brief Initializes a TIMER peripheral.
/// @param timer [OUTPUT] Configured TIMER peripheral
/// @param which Which timer to initialize (0-3)
/// @param prescaler Prescaler value. If NULL, prescaler won't be used.
/// @param int_priority Timer interrupt priority (0 (highest), 15 (lowest)). If NULL, the default priority is set.
void TIMER_Init(_OUT TIMER *const timer, u8 which, _NULLABLE u32 *const prescaler, _NULLABLE u16 *const int_priority);

/// @brief Deconfigures a TIMER peripheral (also match registers).
/// @param timer TIMER peripheral that will be deconfigured
/// @note In order to use the TIMER peripheral again, it must be initialized.
void TIMER_Deinit(_IN TIMER *const timer);

/// @brief  Sets the match value for a match register of a TIMER peripheral
/// @param timer [OUTPUT] Configured (and initialized) TIMER peripheral
/// @param match_reg Match register to set
void TIMER_SetMatch(_OUT TIMER *const timer, _IN TIMER_MatchReg *const match_reg);

/// @brief Unsets a match register of a TIMER peripheral
/// @param timer [OUTPUT] Configured (and initialized) TIMER peripheral
/// @param match_reg Match register to unset. This variable won't be touched.
void TIMER_UnsetMatch(_OUT TIMER *const timer, _IN TIMER_MatchReg *const match_reg);

void TIMER_Enable(_IN TIMER *const timer);
void TIMER_Disable(_IN TIMER *const timer);

/// @brief Resets a TIMER peripheral without deconfiguring it.
/// @note In order to use the TIMER peripheral again, it must be enabled.
void TIMER_Reset(_IN TIMER *const timer);

_INT_HANDLER TIMER0_IRQHandler(void);
_INT_HANDLER TIMER1_IRQHandler(void);
_INT_HANDLER TIMER2_IRQHandler(void);
_INT_HANDLER TIMER3_IRQHandler(void);

#endif
