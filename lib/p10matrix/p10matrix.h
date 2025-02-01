#ifndef _INC_P10MATRIX_H
#define _INC_P10MATRIX_H

#include "p10matrix_conf.h"

void P10_Clear(void);
void P10_SetCursor(unsigned x, unsigned y);
void P10_WriteChar(char c);
void P10_WriteString(const char *s);

void P10_Callback(void);

#endif // _INC_P10MATRIX_H