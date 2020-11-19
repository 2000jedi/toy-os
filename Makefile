# Default make target .

SOURCES = $(wildcard drivers/*.c kernel/*/*.c kernel/*.c)
HEADERS = $(wildcard drivers/*.h kernel/*/*.h kernel/*.h)

# mac-specific elf-friendly linker-ld
LD = /usr/local/i386elfgcc/bin/i386-elf-ld
BOCHS = /Users/yudi/opt/bochs/bin/bochs

OBJ = ${SOURCES:.c=.o kernel/cpu/interrupt.o}

run: all
	qemu-system-i386 -fda toy-os.bin

all: clean image

reset: clean run

image: boot/boot.bin kernel.bin
	cat $^ > toy-os.bin

clean:
	rm -f *.bin *.o toy-os.img kernel/*/*.o kernel/*.o boot/*.bin drivers/*.o

# Link
kernel.bin: boot/kernel_entry.o ${OBJ}
	${LD} -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

# Compile .c sources into object files
%.o: %.c
	clang -g --target=i386-none-elf -ffreestanding -c $< -o $@

# Compile .asm sources into object files
%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

kernel.elf: boot/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^

debug: toy-os.bin kernel.elf
	qemu-system-i386 -s -S -fda toy-os.bin &
	gdb -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"