#include "base.h"

int main(void)
{
    SystemInit();
    LED_Init();
    BTNs_Init();
    RIT_Init(50, 25);
    RIT_Enable();

    // your code

    Power_Init(false, true);
    Power_PowerDownOnWFI();
    Power_WFI();
}