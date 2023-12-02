#  Makefile 
#  by Marina Safwat 
#  1/12/2023

CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -gdwarf-2
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
INCS = -I .
LIBS = 
OUT = toggleLed

all: $(OUT).hex
	@echo "------Build is done------"

%.o: %.s
	$(CC)as $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc $(CFLAGS) $(INCS) -c $< -o $@

$(OUT).elf: $(OBJ) $(ASOBJ)
	$(CC)ld -T linker_script.ld $(OBJ) $(ASOBJ) $(LIBS) -o $@ -Map=output.map

$(OUT).hex: $(OUT).elf
	$(CC)objcopy -O binary $< $@
	
clean:
	rm *.elf *.hex
	@echo "output cleaned"
	
clean_all:
	rm *.o *.elf *.hex
	@echo "Everything clean"