#include "LPC17xx.h"
#include "buttons.h"
#include "config.h"

// External interrupt flags for RIT interfacing (debounced buttons)
#ifdef USE_RIT_DEBOUNCE
_DECL_EXTERNALLY u8 eint0_down, eint1_down, eint2_down;
#endif

_INT_HANDLER EINT0_IRQHandler(void)
{
#ifdef USE_RIT_DEBOUNCE
    eint0_down = 1;
    NVIC_DisableIRQ(EINT0_IRQn);
    CLR_BIT(LPC_PINCON->PINSEL4, 20); // Set P2.10 to 00 (GPIO, previously EINT0)
#else
    // Place your code here
#endif

    LPC_SC->EXTINT &= 1; // Clear the interrupt flag
}

_INT_HANDLER EINT1_IRQHandler(void)
{
#ifdef USE_RIT_DEBOUNCE
    eint1_down = 1;
    NVIC_DisableIRQ(EINT1_IRQn);
    CLR_BIT(LPC_PINCON->PINSEL4, 22); // Set P2.11 to 00 (GPIO, previously EINT1)
#else
    // Place your code here
#endif

    LPC_SC->EXTINT &= 1 << 1; // Clear the interrupt flag
}

_INT_HANDLER EINT2_IRQHandler(void)
{
#ifdef USE_RIT_DEBOUNCE
    eint2_down = 1;
    NVIC_DisableIRQ(EINT2_IRQn);
    CLR_BIT(LPC_PINCON->PINSEL4, 24); // Set P2.12 to 00 (GPIO, previously EINT2)
#else
    // Place your code here
#endif

    LPC_SC->EXTINT &= 1 << 2; // Clear the interrupt flag
}
