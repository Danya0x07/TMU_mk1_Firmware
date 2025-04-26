#include "led.h"
#include "main.h"

void Led_ShowLink(bool linkStart, bool linkFinish)
{
    if (linkStart)
        LL_GPIO_SetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin);
    else
        LL_GPIO_ResetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin);

    if (linkFinish)
        LL_GPIO_SetOutputPin(LED_LINKFINISH_GPIO_Port, LED_LINKFINISH_Pin);
    else
        LL_GPIO_ResetOutputPin(LED_LINKFINISH_GPIO_Port, LED_LINKFINISH_Pin);
}

static void Blink(uint32_t pinMask, unsigned times, unsigned duration)
{
    while (times--) {
        LL_GPIO_SetOutputPin(LED_LINKSTART_GPIO_Port, pinMask);
        HAL_Delay(duration);
        LL_GPIO_ResetOutputPin(LED_LINKSTART_GPIO_Port, pinMask);
        HAL_Delay(duration >> 1);
    }
}

void Led_BlinkStart(unsigned times, unsigned duration)
{
    Blink(LED_LINKSTART_Pin, times, duration);
}

void Led_BlinkFinish(unsigned times, unsigned duration)
{
    Blink(LED_LINKFINISH_Pin, times, duration);
}

void Led_BlinkBoth(unsigned times, unsigned duration)
{
    Blink(LED_LINKSTART_Pin | LED_LINKFINISH_Pin, times, duration);
}

void Led_BlinkAlternate(unsigned times, unsigned duration)
{
    times = (times << 1) - 1;
    duration >>= 1;
    LL_GPIO_ResetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin | LED_LINKFINISH_Pin);
    LL_GPIO_SetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin);
    HAL_Delay(duration);
    while (times--) {
        LL_GPIO_TogglePin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin | LED_LINKFINISH_Pin);
        HAL_Delay(duration);
    }
    LL_GPIO_ResetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin | LED_LINKFINISH_Pin);
}