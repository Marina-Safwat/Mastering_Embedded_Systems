/*
 * MemoryMap.h
 *
 * Created: 2/1/2024 10:35:11 AM
 *  Author: VTM
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

//GPIO Registers

//PortD
#define PORTD (*(volatile unsigned char*)(0x32))
#define DDRD (*(volatile unsigned char*)(0x31))
#define PIND (*(volatile unsigned char*)(0x30))

#endif /* MEMORYMAP_H_ */