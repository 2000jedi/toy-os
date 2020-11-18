#ifndef DRV_SCRN_H
#define DRV_SCRN_H

#define VIDEO_ADDRESS 0xb8000
#define DRV_MAX_ROWS 25
#define DRV_MAX_COLS 80
#define WHITE_ON_BLACK 0x0f
#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5

void vmem_flush(void);
void vmem_roll(void);
void vmem_putc(char pchar, char attr, char row, char col);

#endif
