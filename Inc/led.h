#ifndef _INC_LED_H
#define _INC_LED_H

#include <stdbool.h>

void Led_ShowLink(bool linkStart, bool linkFinish);
void Led_BlinkStart(unsigned times, unsigned duration);
void Led_BlinkFinish(unsigned times, unsigned duration);
void Led_BlinkBoth(unsigned times, unsigned duration);
void Led_BlinkAlternate(unsigned times, unsigned duration);

#endif // _INC_LED_H