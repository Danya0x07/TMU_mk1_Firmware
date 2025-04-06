#include "p10txt.h"
#include "p10txt_font.h"

#define ROW_LEN (P10_PANEL_DOTS_X * P10_PANELS_X)

static struct {
    int row;
    int col;
} cursor;

void P10_SetCursor(int row, int col)
{
    cursor.row = row;
    cursor.col = col;
}

void P10_PrintChar_5x7(char c)
{
    const uint8_t *bitmap = GetCharacterBitmap(c);
    const struct P10_Image img = {5, 7, bitmap};

    P10_DrawImage(&img, cursor.col, cursor.row * 8);

    cursor.col += 6;
    if (cursor.col >= ROW_LEN) {
        cursor.row++;
        cursor.col -= ROW_LEN;
    }
}

void P10_PrintString_5x7(const char *s)
{
    while (*s) {
        P10_PrintChar_5x7(*s++);
    }
}
