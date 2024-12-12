#ifndef BUTTONS_H
#define BUTTONS_H

#include "utils.h"

void BTNs_Init();

// Interrupt function names must be kept in sync with the symbols
// defined in the interrupt vector table in the .s file.
_INT_HANDLER EINT0_IRQHandler(void);
_INT_HANDLER EINT1_IRQHandler(void);
_INT_HANDLER EINT2_IRQHandler(void);

#endif