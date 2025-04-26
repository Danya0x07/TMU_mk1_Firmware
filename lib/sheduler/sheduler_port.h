#ifndef _INC_SHEDULER_PORT_H
#define _INC_SHEDULER_PORT_H

#include "main.h"

static inline uint32_t Millis_Get(void)
{
    return HAL_GetTick();
}

#endif