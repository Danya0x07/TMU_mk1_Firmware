#ifndef _INC_P10MATRIX_H
#define _INC_P10MATRIX_H

#include <stdint.h>
#include "p10matrix_conf.h"

struct P10_Image {
    int n, m;
    const uint8_t *data;
};

void P10_Clear(void);
void P10_DrawImage(const struct P10_Image *img, int dotX, int dotY);

void P10_Callback(void);

#endif // _INC_P10MATRIX_H