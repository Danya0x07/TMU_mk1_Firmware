#include "p10matrix.h"
#include "p10matrix_port.h"
#include <string.h>

#define BYTES_X   (P10_STRIPS_X)
#define BYTES_Y   (P10_STRIPS_Y / 4)

#define FRAME_MEM_SIZE  (BYTES_X * BYTES_Y)

static uint8_t videoMemory[4][FRAME_MEM_SIZE];

void P10_Clear(void)
{
    memset((uint8_t *)videoMemory, 0, sizeof(videoMemory));
}

static void WriteByte(int stripX, int stripY, uint8_t data)
{
    IRQ_OFF();

    int row = stripY / P10_PANEL_STRIPS_Y;
    int pos = stripY & (P10_PANEL_STRIPS_Y - 1);
    unsigned coordinate = 4 * stripX + 4 * P10_STRIPS_X * row + (P10_PANEL_STRIPS_Y - 1 - pos) / 4;

    if (coordinate >= FRAME_MEM_SIZE)
        return;

    videoMemory[stripY & 3][FRAME_MEM_SIZE - 1 - coordinate] = data;

    IRQ_ON();
}

static uint8_t ReadByte(int stripX, int stripY)
{
    int row = stripY / P10_PANEL_STRIPS_Y;
    int pos = stripY & (P10_PANEL_STRIPS_Y - 1);
    unsigned coordinate = 4 * stripX + 4 * P10_STRIPS_X * row + (P10_PANEL_STRIPS_Y - 1 - pos) / 4;

    if (coordinate >= FRAME_MEM_SIZE)
        return 0;

    return videoMemory[stripY & 3][FRAME_MEM_SIZE - 1 - coordinate];
}

static inline uint8_t ReadByteOfImageData(const uint8_t *data, unsigned nBytesX, unsigned byteY, unsigned byteX)
{
    if (byteX >= nBytesX)
        return 0;
    return data[nBytesX * byteY + byteX];
}

static uint8_t ComputeMask(int nDots, int startStripX, int stripX, int endStripX, int xShift)
{
    uint8_t startMask = 0xFF >> xShift;
    uint8_t midMask = 0xFF;
    uint8_t endMask = 0xFF << (8 - (nDots - (8 - xShift) - 8 * (endStripX - startStripX - 1)));

    uint8_t mask = midMask;

    if (stripX == startStripX)
        mask &= startMask;
    if (stripX == endStripX)
        mask &= endMask;

    return mask;
}

static uint8_t GetImagePart(const struct P10_Image *img,
                            int startStripX, int stripX, int endStripX,
                            int xShift, int startStripY, int stripY)
{
    uint_fast8_t byteY = stripY - startStripY;
    uint_fast8_t nBytesX = (img->n - 1) / 8 + 1;
    uint_fast8_t byteX = stripX - startStripX;
    uint8_t rByte = ReadByteOfImageData(img->data, nBytesX, byteY, byteX) >> xShift;
    uint8_t lByte = ReadByteOfImageData(img->data, nBytesX, byteY, byteX - 1) << (8 - xShift);

    return lByte | rByte;
}

void P10_DrawImage(const struct P10_Image *img, int dotX, int dotY)
{
    int startStripX = dotX / 8;
    int endStripX = (dotX + img->n) / 8;
    int xShift = dotX & 7;
    int startStripY = dotY;
    int endStripY = dotY + img->m - 1;

    for (int stripX = startStripX; stripX <= endStripX; stripX++) {
        uint8_t mask = ComputeMask(img->n, startStripX, stripX, endStripX, xShift);

        for (int stripY = startStripY; stripY <= endStripY; stripY++) {
            uint8_t imgData = GetImagePart(img, startStripX, stripX, endStripX, xShift, startStripY, stripY);
            uint8_t oldData = ReadByte(stripX, stripY);
            uint8_t newData = (oldData & ~mask) | (imgData & mask);

            WriteByte(stripX, stripY, newData);
        }
    }
}

void P10_Callback(void)
{
    static unsigned scanCounter;

    SCLK_LOW();
    ShiftOutBytes((uint8_t *)&videoMemory[scanCounter][0], FRAME_MEM_SIZE);
    SCLK_HIGH();

    SetScanStep(scanCounter++);
    scanCounter &= 0b11;
}