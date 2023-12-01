#  Makefile 
#  by Marina Safwat 
#  1/12/2023

CC = arm-none-eabi-
CFLAGS = -mcpu=arm926ej-s -g
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
INCS = -I .
LIBS = 

all: lab1.bin
	@echo "------Build is done------"

startup.o: startup.s
	$(CC)as $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc $(CFLAGS) $(INCS) -c $< -o $@

lab1.elf: $(OBJ) $(ASOBJ)
	$(CC)ld -T linker_script.ld $(OBJ) $(ASOBJ) $(LIBS) -o $@ -Map=output.map

lab1.bin: lab1.elf
	$(CC)objcopy -O binary $< $@
	
clean:
	rm *.elf *.bin
	@echo "output cleaned"
	
clean_all:
	rm *.o *.elf *.bin
	@echo "Everything clean"