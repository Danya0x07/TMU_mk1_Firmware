#include "p10matrix.h"
#include "p10matrix_port.h"
#include "string.h"

static volatile uint8_t videoMemory[4][16];
static volatile uint_fast8_t scanCounter;
static volatile uint_fast8_t cursorX, cursorY;

void P10_Clear(void)
{
    memset((uint8_t *)videoMemory, 0, sizeof(videoMemory));
}

void P10_SetCursor(unsigned x, unsigned y)
{
    cursorX = x;
    cursorY = y;
}

void P10_WriteChar(char c)
{
    videoMemory[0][4 * cursorX + cursorY] = c;
}

void P10_WriteString(const char *s)
{
    while (*s)
        P10_WriteChar(*s++);
}

void P10_Callback(void)
{
    SCLK_LOW();
    ShiftOutBytes((uint8_t *)&videoMemory[scanCounter][0], sizeof(videoMemory) >> 2);
    SCLK_HIGH();

    SetScanStep(scanCounter++);
    scanCounter &= 0b11;
}