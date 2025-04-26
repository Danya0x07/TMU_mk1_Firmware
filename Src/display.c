#include "display.h"
#include "main.h"
#include <p10txt.h>
#include <stdio.h>

void Display_ShowSplashScreen(void)
{
    P10_Clear();
    P10_SetCursor(0, 7);
    P10_PrintString_5x7("TMU");
    P10_SetCursor(1, 7);
    P10_PrintString_5x7("mk1");
    HAL_Delay(3000);

    P10_Clear();
    P10_SetCursor(1, 4);
    P10_PrintString_5x7(FIRMWARE_VERSION);
    HAL_Delay(3000);

    P10_Clear();
    P10_SetCursor(0, 10);
    P10_PrintString_5x7("by");
    P10_SetCursor(1, 0);
    P10_PrintString_5x7("R3BCI");
    HAL_Delay(3000);
}

void Display_DrawTimeFrame(void)
{
    P10_Clear();
    P10_SetCursor(0, 1);
    P10_PrintString_5x7("00:00");
    P10_SetCursor(1, 7);
    P10_PrintString_5x7("000");
}

void Display_UpdateTime(unsigned min, unsigned sec, unsigned ms)
{
    char str[6];
    snprintf(str, sizeof(str), "%02d:%02d", min, sec);
    P10_SetCursor(0, 1);
    P10_PrintString_5x7(str);
    P10_SetCursor(1, 7);
    snprintf(str, sizeof(str), "%03d", ms);
    P10_PrintString_5x7(str);
}

