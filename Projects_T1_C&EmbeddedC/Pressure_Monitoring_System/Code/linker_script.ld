/*************************
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : linker_script.ld
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
*************************/
MEMORY
{
	flash (rx) : ORIGIN = 0x08000000, LENGTH = 128k
	sram (rwx) : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = .;
	}> flash
	.data :
	{
		_S_data = . ;
		*(.data*)
		_E_data = . ;
	}>sram AT> flash
	.debug :
	{
		*(.debug*)
	}
	.bss :
	{
		_S_bss = .;
		*(.bss.*)
		. = ALIGN(4);
		_E_bss = .;
		. = . + 0x1000;
		_stack_top = .;
	}>sram
}