#include "stdio.h"
#include "../../drivers/screen.h"

static int row = 0;
static int col = 0;

void putc(char c) {
    if (col >= DRV_MAX_ROWS) return;
    if (row == DRV_MAX_ROWS) vmem_roll();
    switch (c) {
        case '\n': {
            row ++;
            col = 0;
            return;
        }
        case '\r': {
            col = 0;
            return;
        }
        default: {
            vmem_putc(c, WHITE_ON_BLACK, row, col);
            col ++;
        }
    }
}

void puts(char* str, int n) {
    for (int i = 0; (i < n) && (*str != '\0'); ++i, ++str) {
        putc(*str);
    }
}
