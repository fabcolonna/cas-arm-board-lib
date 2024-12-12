#include "debouncer.h"
#include "LPC17xx.h"
#include "utils.h"

void RIT_Init(u32 ival_ms, u32 pclk_mhz)
{
    CLR_BITS(LPC_SC->PCLKSEL1, 3, 26);
    SET_BIT(LPC_SC->PCKLSEL1, 26);
    SET_BIT(LPC_SC->PCONP, 16);

    LPC_RIT->RICOMPVAL = (pclk_mhz * ival_ms * 1000);
    LPC_RIT->RICTRL = 6; // Clear on match + Timer enable for debug
    LPC_RIT->RICOUNTER = 0;

    // Enabling interrupts coming from RIT
    NVIC_EnableIRQ(RIT_IRQn);
}

void RIT_Enable(void)
{
    SET_BIT(LPC_RIT->RITCRL, 3);
}

void RIT_Disable(void)
{
    CLR_BIT(LPC_RIT->RITCRL, 3);
}

void RIT_Reset(void)
{
    LPC_RIT->RICOUNTER = 0;
}