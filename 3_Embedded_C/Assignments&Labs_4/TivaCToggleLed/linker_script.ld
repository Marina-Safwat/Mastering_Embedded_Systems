/*	linker_script
	by Marina Safwat
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x00000000, LENGTH = 512k
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512k
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text)
		*(.rodata)
		_E_text = .;
	}>flash
	.data : {
		_S_data = .;
		*(.data)
		. = ALIGN(4);
		_E_data = .;
	}> sram AT> flash
	.bss : {
		_S_bss = .;
		*(.bss)
		_E_bss = .;
	}>sram

}