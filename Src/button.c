#include "button.h"

#define BTN_MASK    (BTN_START | BTN_STOP)

static uint32_t prevState, state, pressed, released;
static bool updateFlag;

void Button_Reset(void)
{
    prevState = state = pressed = released = 0;
    updateFlag = false;
}

void Button_ReadState(void)
{
    state = LL_GPIO_ReadInputPort(BTN_START_GPIO_Port) & BTN_MASK;

    uint32_t diff = prevState ^ state;
    pressed = diff & state;
    released = diff & ~state;

    prevState = state;
}

bool Button_IsPressed(uint32_t btn)
{
    return (state & btn) != 0;
}

bool Button_HasBeenPressed(uint32_t btn)
{
    return (pressed & btn) != 0;
}

bool Button_HasBeenReleased(uint32_t btn)
{
    return (released & btn) != 0;
}

void Button_SetUpdateFlag(void)
{
    updateFlag = true;
}

void Button_ClearUpdateFlag(void)
{
    updateFlag = false;
}

bool Button_IsUpdateFlagSet(void)
{
    return updateFlag;
}