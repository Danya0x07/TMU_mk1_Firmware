#ifndef _INC_TIMER_H
#define _INC_TIMER_H

typedef enum {
    TimerState_IDLE,
    TimerState_RUN,
    TimerState_HALT
} TimerState;

void Timer_Start(void);
void Timer_Stop(void);
void Timer_Reset(void);
void Timer_GetTime(unsigned *min, unsigned *sec, unsigned *ms);
TimerState Timer_GetState(void);

void Timer_SecondElapsed(void);

#endif // _INC_TIMER_H