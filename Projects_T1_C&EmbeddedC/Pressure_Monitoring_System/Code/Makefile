#*************************************************************************/
# Author        : Marina Safwat Barsoum Gerges
# Project       : Pressure_Monitoring_System_Project
# File          : Makefile
# Date          : Dec 29, 2023
# GitHub        : https://github.com/Marina-Safwat
#*************************************************************************/

CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -mthumb -gdwarf-2
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
INCS = -I .
LIBS = 
OUT = PressureMonitoringSystem

all: $(OUT).hex $(OUT).bin
	@echo "------Build is done------"

%.o: %.s
	$(CC)as $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc $(CFLAGS) $(INCS) -c $< -o $@

$(OUT).elf: $(OBJ) $(ASOBJ)
	$(CC)ld -T linker_script.ld $(OBJ) $(ASOBJ) $(LIBS) -o $@ -Map=output.map

$(OUT).hex: $(OUT).elf
	$(CC)objcopy -O ihex $< $@
	
$(OUT).bin: $(OUT).elf
	$(CC)objcopy -O binary $< $@
	
clean:
	rm *.elf *.hex
	@echo "output cleaned"
	
clean_all:
	rm *.o *.elf *.hex *.bin
	@echo "Everything clean"