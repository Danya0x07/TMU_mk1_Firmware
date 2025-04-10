#ifndef _INC_P10TXT_FONT_H
#define _INC_P10TXT_FONT_H

const uint8_t ASCII_5X7[][8] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // SPACE
    {0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x20},  // !
    {0x50, 0x50, 0x50, 0x00, 0x00, 0x00, 0x00},  // "
    {0x50, 0x50, 0xF8, 0x50, 0xF8, 0x50, 0x50},  // #
    {0x20, 0x78, 0xA0, 0x70, 0x28, 0xF0, 0x20},  // $
    {0xC0, 0xC8, 0x10, 0x20, 0x40, 0x98, 0x18},  // %
    {0x60, 0x90, 0xA0, 0x40, 0xA8, 0x90, 0x68},  // &
    {0x60, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00},  // '
    {0x10, 0x20, 0x40, 0x40, 0x40, 0x20, 0x10},  // (
    {0x40, 0x20, 0x10, 0x10, 0x10, 0x20, 0x40},  // )
    {0x00, 0x20, 0xA8, 0x70, 0xA8, 0x20, 0x00},  // *
    {0x00, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x00},  // +
    {0x00, 0x00, 0x00, 0x00, 0x60, 0x20, 0x40},  // ,
    {0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00},  // -
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60},  // .
    {0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00},  // /
    {0x70, 0x88, 0x98, 0xA8, 0xC8, 0x88, 0x70},  // 0
    {0x20, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70},  // 1
    {0x70, 0x88, 0x08, 0x10, 0x20, 0x40, 0xF8},  // 2
    {0xF8, 0x10, 0x20, 0x10, 0x08, 0x88, 0x70},  // 3
    {0x10, 0x30, 0x50, 0x90, 0xF8, 0x10, 0x10},  // 4
    {0xF8, 0x80, 0xF0, 0x08, 0x08, 0x88, 0x70},  // 5
    {0x30, 0x40, 0x80, 0xF0, 0x88, 0x88, 0x70},  // 6
    {0xF8, 0x08, 0x10, 0x20, 0x40, 0x40, 0x40},  // 7
    {0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70},  // 8
    {0x70, 0x88, 0x88, 0x78, 0x08, 0x10, 0x60},  // 9
    {0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00},  // :
    {0x00, 0x60, 0x60, 0x00, 0x60, 0x20, 0x40},  // ;
    {0x10, 0x20, 0x40, 0x80, 0x40, 0x20, 0x10},  // <
    {0x00, 0x00, 0xF8, 0x00, 0xF8, 0x00, 0x00},  // =
    {0x40, 0x20, 0x10, 0x08, 0x10, 0x20, 0x40},  // >
    {0x70, 0x88, 0x08, 0x10, 0x20, 0x00, 0x20},  // ?
    {0x70, 0x88, 0x08, 0x68, 0xA8, 0xA8, 0x70},  // @
    {0x70, 0x88, 0x88, 0x88, 0xF8, 0x88, 0x88},  // A
    {0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0xF0},  // B
    {0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70},  // C
    {0xE0, 0x90, 0x88, 0x88, 0x88, 0x90, 0xE0},  // D
    {0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF8},  // E
    {0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0x80},  // F
    {0x70, 0x88, 0x80, 0xB8, 0x88, 0x88, 0x78},  // G
    {0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88},  // H
    {0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70},  // I
    {0x38, 0x10, 0x10, 0x10, 0x10, 0x90, 0x60},  // J
    {0x88, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x88},  // K
    {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xF8},  // L
    {0x88, 0xD8, 0xA8, 0xA8, 0x88, 0x88, 0x88},  // M
    {0x88, 0x88, 0xC8, 0xA8, 0x98, 0x88, 0x88},  // N
    {0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70},  // O
    {0xF0, 0x88, 0x88, 0xF0, 0x80, 0x80, 0x80},  // P
    {0x70, 0x88, 0x88, 0x88, 0xA8, 0x90, 0x68},  // Q
    {0xF0, 0x88, 0x88, 0xF0, 0xA0, 0x90, 0x88},  // R
    {0x78, 0x80, 0x80, 0x70, 0x08, 0x08, 0xF0},  // S
    {0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},  // T
    {0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70},  // U
    {0x88, 0x88, 0x88, 0x88, 0x88, 0x50, 0x20},  // V
    {0x88, 0x88, 0x88, 0xA8, 0xA8, 0xA8, 0x50},  // W
    {0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88},  // X
    {0x88, 0x88, 0x88, 0x50, 0x20, 0x20, 0x20},  // Y
    {0xF8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8},  // Z
    {0x70, 0x40, 0x40, 0x40, 0x40, 0x40, 0x70},  // [
    {0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00},  /* \ */
    {0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70},  // ]
    {0x20, 0x50, 0x88, 0x00, 0x00, 0x00, 0x00},  // ^
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8},  // _
    {0x40, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00},  // `
    {0x00, 0x00, 0x70, 0x08, 0x78, 0x88, 0x78},  // a
    {0x80, 0x80, 0xB0, 0xC8, 0x88, 0x88, 0xF0},  // b
    {0x00, 0x00, 0x70, 0x80, 0x80, 0x88, 0x70},  // c
    {0x08, 0x08, 0x68, 0x98, 0x88, 0x88, 0x78},  // d
    {0x00, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x70},  // e
    {0x30, 0x48, 0x40, 0xE0, 0x40, 0x40, 0x40},  // f
    {0x00, 0x78, 0x88, 0x88, 0x78, 0x08, 0x70},  // g
    {0x80, 0x80, 0xB0, 0xC8, 0x88, 0x88, 0x88},  // h
    {0x20, 0x00, 0x60, 0x20, 0x20, 0x20, 0x70},  // i
    {0x10, 0x00, 0x30, 0x10, 0x10, 0x90, 0x60},  // j
    {0x80, 0x80, 0x90, 0xA0, 0xC0, 0xA0, 0x90},  // k
    {0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70},  // l
    {0x00, 0x00, 0xD0, 0xA8, 0xA8, 0x88, 0x88},  // m
    {0x00, 0x00, 0xB0, 0xC8, 0x88, 0x88, 0x88},  // n
    {0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70},  // o
    {0x00, 0x00, 0xF0, 0x88, 0xF0, 0x80, 0x80},  // p
    {0x00, 0x00, 0x68, 0x98, 0x78, 0x08, 0x08},  // q
    {0x00, 0x00, 0xB0, 0xC8, 0x80, 0x80, 0x80},  // r
    {0x00, 0x00, 0x70, 0x80, 0x70, 0x08, 0xF0},  // s
    {0x40, 0x40, 0xE0, 0x40, 0x40, 0x48, 0x30},  // t
    {0x00, 0x00, 0x88, 0x88, 0x88, 0x98, 0x68},  // u
    {0x00, 0x00, 0x88, 0x88, 0x88, 0x50, 0x20},  // v
    {0x00, 0x00, 0x88, 0x88, 0xA8, 0xA8, 0x50},  // w
    {0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88},  // x
    {0x00, 0x00, 0x88, 0x88, 0x78, 0x08, 0x70},  // y
    {0x00, 0x00, 0xF8, 0x10, 0x20, 0x40, 0xF8},  // z
    {0x10, 0x20, 0x20, 0x40, 0x20, 0x20, 0x10},  // {
    {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},  // |
    {0x40, 0x20, 0x20, 0x10, 0x20, 0x20, 0x40},  // }
    {0x00, 0x00, 0x00, 0x68, 0x90, 0x00, 0x00}   // ~
};

const uint8_t RUSSIAN_5x7[][8] = {
    {0x70, 0x88, 0x88, 0x88, 0xF8, 0x88, 0x88},
    {0xF8, 0x88, 0x80, 0xF0, 0x88, 0x88, 0xF0},
    {0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0xF0},
    {0xF8, 0x88, 0x80, 0x80, 0x80, 0x80, 0x80},
    {0x78, 0x28, 0x28, 0x28, 0x48, 0x88, 0xF8},
    {0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF8},
    {0xA8, 0xA8, 0xA8, 0x70, 0xA8, 0xA8, 0xA8},
    {0xF0, 0x08, 0x08, 0x70, 0x08, 0x08, 0xF0},
    {0x88, 0x88, 0x98, 0xA8, 0xC8, 0x88, 0x88},
    {0x50, 0x20, 0x88, 0x98, 0xA8, 0xC8, 0x88},
    {0x88, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x88},
    {0x78, 0x28, 0x28, 0x28, 0x28, 0xA8, 0x48},
    {0x88, 0xD8, 0xA8, 0xA8, 0x88, 0x88, 0x88},
    {0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88},
    {0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70},
    {0xF8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88},
    {0xF0, 0x88, 0x88, 0xF0, 0x80, 0x80, 0x80},
    {0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70},
    {0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
    {0x88, 0x88, 0x88, 0x50, 0x20, 0x40, 0x80},
    {0x20, 0x70, 0xA8, 0xA8, 0xA8, 0x70, 0x20},
    {0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88},
    {0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xF8},
    {0x88, 0x88, 0x88, 0x78, 0x08, 0x08, 0x08},
    {0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xF8},
    {0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xF8},
    {0xC0, 0x40, 0x40, 0x70, 0x48, 0x48, 0x70},
    {0x88, 0x88, 0x88, 0xC8, 0xA8, 0xA8, 0xC8},
    {0x40, 0x40, 0x40, 0x70, 0x48, 0x48, 0x70},
    {0x70, 0x88, 0x08, 0x38, 0x08, 0x88, 0x70},
    {0x90, 0xA8, 0xA8, 0xE8, 0xA8, 0xA8, 0x90},
    {0x78, 0x88, 0x88, 0x78, 0x28, 0x48, 0x88},
    {0x00, 0x00, 0x70, 0x08, 0x78, 0x88, 0x78},
    {0x18, 0x60, 0x80, 0xF0, 0x88, 0x88, 0x70},
    {0x00, 0x00, 0xE0, 0x90, 0xE0, 0x90, 0xE0},
    {0x00, 0x00, 0xF8, 0x88, 0x80, 0x80, 0x80},
    {0x00, 0x00, 0x78, 0x28, 0x48, 0x88, 0xF8},
    {0x00, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x70},
    {0x00, 0x00, 0xA8, 0xA8, 0x70, 0xA8, 0xA8},
    {0x00, 0x00, 0xF0, 0x08, 0x30, 0x08, 0xF0},
    {0x00, 0x00, 0x88, 0x98, 0xA8, 0xC8, 0x88},
    {0x50, 0x20, 0x88, 0x88, 0x98, 0xA8, 0xC8},
    {0x00, 0x00, 0x90, 0xA0, 0xC0, 0xA0, 0x90},
    {0x00, 0x00, 0x78, 0x28, 0x28, 0xA8, 0x48},
    {0x00, 0x00, 0x88, 0xD8, 0xA8, 0x88, 0x88},
    {0x00, 0x00, 0x88, 0x88, 0xF8, 0x88, 0x88},
    {0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70},
    {0x00, 0x00, 0xF8, 0x88, 0x88, 0x88, 0x88},
    {0x00, 0x00, 0xF0, 0x88, 0xF0, 0x80, 0x80},
    {0x00, 0x00, 0x70, 0x80, 0x80, 0x88, 0x70},
    {0x00, 0x00, 0xF8, 0x20, 0x20, 0x20, 0x20},
    {0x00, 0x00, 0x88, 0x88, 0x78, 0x08, 0x70},
    {0x00, 0x00, 0x20, 0x70, 0xA8, 0xA8, 0x70},
    {0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88},
    {0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0xF8},
    {0x00, 0x00, 0x88, 0x88, 0x78, 0x08, 0x08},
    {0x00, 0x00, 0xA8, 0xA8, 0xA8, 0xA8, 0xF8},
    {0x00, 0x00, 0xA8, 0xA8, 0xA8, 0xA8, 0xF8},
    {0x00, 0x00, 0xC0, 0x40, 0x70, 0x48, 0x70},
    {0x00, 0x00, 0x88, 0x88, 0xE8, 0x98, 0xE8},
    {0x00, 0x00, 0x80, 0x80, 0xE0, 0x90, 0xE0},
    {0x00, 0x00, 0x70, 0x88, 0x38, 0x88, 0x70},
    {0x00, 0x00, 0x90, 0xA8, 0xE8, 0xA8, 0x90},
    {0x00, 0x00, 0x78, 0x88, 0x78, 0x28, 0x48},
    {0x50, 0x00, 0xF8, 0x80, 0xF0, 0x80, 0xF8},
    {0x50, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x70}
};

static const uint8_t *GetCharacterBitmap(char c)
{
    const uint8_t *bitmap;

    if (c >= 0x80) {  // non-ASCII character
        c = c < 0xE0 ? c - 0x80 : c - 0xB0;
        bitmap = (const uint8_t *)&RUSSIAN_5x7[(uint8_t)c];
    }
    else {
        bitmap = (const uint8_t *)&ASCII_5X7[(uint8_t)c - 0x20];
    }

    return bitmap;
}

#endif // _INC_P10TXT_FONT_H