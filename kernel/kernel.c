#include "kernel.h"
#include "io/stdio.h"
#include "io/memory.h"
#include "cpu/isr.h"
#include "../drivers/screen.h"

void main() {
  vmem_flush();
  puts("Video initialize ... OK\n", 25);
  puts("Interrupt inject ... ", 22);
  isr_install();
  puts("OK\n", 4);

  puts("Hello, World!\n", 14);
  char iv[3];
  itoa(123, iv);
  puts(iv, 3);
  putc('\n');
  
  return;
}
