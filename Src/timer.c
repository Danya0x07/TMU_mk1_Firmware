#include "timer.h"
#include "main.h"

static volatile unsigned seconds;

void Timer_Start(void)
{
    LL_TIM_EnableCounter(TIM3);
}

void Timer_Stop(void)
{
    LL_TIM_DisableCounter(TIM3);
}

void Timer_Reset(void)
{
    LL_TIM_SetCounter(TIM3, 0);
    NVIC_DisableIRQ(TIM3_IRQn);
    seconds = 0;
    NVIC_EnableIRQ(TIM3_IRQn);
}

void Timer_GetTime(unsigned *min, unsigned *sec, unsigned *ms)
{
    unsigned _sec = seconds;
    *min = _sec / 60;
    *sec = _sec % 60;
    *ms = LL_TIM_GetCounter(TIM3);
}

TimerState Timer_GetState(void)
{
    return LL_TIM_IsEnabledCounter(TIM3) ? TimerState_RUN :
            seconds != 0 ? TimerState_HALT : TimerState_IDLE;
}

void Timer_SecondElapsed(void)
{
    seconds++;
}