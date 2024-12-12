#include "LPC17xx.h"
#include "config.h"
#include "debouncer.h"

#ifdef USE_RIT_DEBOUNCE
_USER_EXTERNALLY u8 eint0_down = false, eint1_down = false, eint2_down = false;
#endif

_INT_HANDLER RIT_IRQHandler(void)
{
#ifdef USE_RIT_DEBOUNCE
    if (eint0_down)
    {
        eint0_down++;

        // If P2.10 is low, button is pressed
        if ((LPC_GPIO2->FIOPIN & (1 << 10)) == 0)
        {
            if (eint0_down == 2)
                handle_eint0();
        }
        // Button released
        else
        {
            eint0_down = 0;
            NVIC_EnableIRQ(EINT0_IRQn);       // Enabling the interrupt again
            SET_BIT(LPC_PINCON->PINSEL4, 20); // Set P2.10 back to 01 (EINT0)
        }
    }

    if (eint1_down)
    {
        eint1_down++;

        // If P2.10 is low, button is pressed
        if ((LPC_GPIO2->FIOPIN & (1 << 11)) == 0)
        {
            if (eint1_down == 2)
                handle_eint1();
        }
        // Button released
        else
        {
            eint1_down = 0;
            NVIC_EnableIRQ(EINT1_IRQn);       // Enabling the interrupt again
            SET_BIT(LPC_PINCON->PINSEL4, 22); // Set P2.11 back to 01 (EINT1)
        }
    }

    if (eint2_down)
    {
        eint2_down++;

        // If P2.10 is low, button is pressed
        if ((LPC_GPIO2->FIOPIN & (1 << 12)) == 0)
        {
            if (eint2_down == 2)
                handle_eint2();
        }
        // Button released
        else
        {
            eint2_down = 0;
            NVIC_EnableIRQ(EINT2_IRQn);       // Enabling the interrupt again
            SET_BIT(LPC_PINCON->PINSEL4, 24); // Set P2.12 back to 01 (EINT2)
        }
    }
#endif
}

#ifdef USE_RIT_DEBOUNCE
void handle_eint0(void)
{
    // Place your code here
}

void handle_eint1(void)
{
    // Place your code here
}

void handle_eint2(void)
{
    // Place your code here
}
#endif
