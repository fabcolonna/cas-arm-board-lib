#ifndef __POWER_H
#define __POWER_H

#include "utils.h"

/// @brief Configures sleep/power down mode for the device.
/// @param deep Enables DEEP modes
/// @param sleep_on_exit Whether to enter sleep mode on exit from an ISR
void Power_Init(bool deep, bool sleep_on_exit);

/// @brief WFI/WFE puts device to sleep or deep sleep mode depending on
///        the configuration specified in the Power_Init function.
void Power_SleepOnWFI(void);

/// @brief WFI/WFE puts device to power down power down mode.
void Power_PowerDownOnWFI(void);

/// @brief WFI/WFE puts device to deep power down mode
///        provided that the SLEEPDEEP bit is set.
void Power_DeepPowerDownOnWFI(void);

/// @brief Turns on a peripheral.
/// @param peripheral The bit # of the peripheral to turn on.
/// @example Power_TurnOnPeripheral(22) which turns on TIMER2.
/// @note Bit # can be found in the user manual @ Table 46.
void Power_TurnOnPeripheral(u8 bit);

/// @brief Turns off a peripheral.
/// @param peripheral The bit # of the peripheral to turn off.
/// @example Power_TurnOffPeripheral(22) which turns off TIMER2.
/// @note Bit # can be found in the user manual @ Table 46.
void Power_TurnOffPeripheral(u8 bit);

// WFI function

_INLINE void Power_WFI(void)
{
    __ASM("wfi");
}

#endif
