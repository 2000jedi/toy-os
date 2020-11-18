#include "screen.h"
#include "../kernel/kernel.h"

struct vmem {
  char pchar;
  char attr;
};

static struct vmem (*video_memory)[DRV_MAX_COLS] =
  (struct vmem (*)[DRV_MAX_COLS])VIDEO_ADDRESS;

void vmem_flush(void) {
  for (int row = 0; row < DRV_MAX_ROWS; ++ row) {
    for (int col = 0; col < DRV_MAX_COLS; ++ col) {
      vmem_putc(' ', WHITE_ON_BLACK, row, col);
    }
  }
}

void vmem_roll(void) {
  for (int row = 0; row < DRV_MAX_ROWS - 1; ++ row) {
    for (int col = 0; col < DRV_MAX_COLS; ++ col) {
      video_memory[row][col] = video_memory[row + 1][col];
    }
  }

  for (int col = 0; col < DRV_MAX_COLS; ++ col) {
    vmem_putc(' ', WHITE_ON_BLACK, DRV_MAX_ROWS - 1, col);
  }
}

void vmem_putc(char pchar, char attr, char row, char col) {
  video_memory[row][col].pchar = pchar;
  video_memory[row][col].attr = attr;
}
