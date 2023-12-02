/* 	startup_cortexM3.s
	by Marina Safwat
*/

/* SRAM 0x20000000 */

.section .vectors 
.word 0x20001000
.word _reset
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler

.section .text
_reset:
	bl main
	b .

.thumb_func
	
vector_handler:
	b _reset