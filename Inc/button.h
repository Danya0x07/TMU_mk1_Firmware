#ifndef _INC_BUTTON_H
#define _INC_BUTTON_H

#include <stdbool.h>
#include "main.h"

#define BTN_START   GPIO_PIN_8
#define BTN_STOP    GPIO_PIN_9

#define BUTTON_IRQ_ON()     NVIC_EnableIRQ(EXTI9_5_IRQn)
#define BUTTON_IRQ_OFF()    NVIC_DisableIRQ(EXTI9_5_IRQn)

void Button_Reset(void);
void Button_ReadState(void);
bool Button_IsPressed(uint32_t btn);
bool Button_HasBeenPressed(uint32_t btn);
bool Button_HasBeenReleased(uint32_t btn);

void Button_SetUpdateFlag(void);
void Button_ClearUpdateFlag(void);
bool Button_IsUpdateFlagSet(void);

#endif // _INC_BUTTON_H