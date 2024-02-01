/*
 * MemoryMap.h
 *
 * Created: 2/1/2024 10:35:11 AM
 *  Author: VTM
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

//GPIO Registers

//PortA
#define PORTA (*(volatile unsigned char*)(0x3B))
#define DDRA (*(volatile unsigned char*)(0x3A))
#define PINA (*(volatile unsigned char*)(0x39))

//PortB
#define PORTB (*(volatile unsigned char*)(0x38))
#define DDRB (*(volatile unsigned char*)(0x37))
#define PINB (*(volatile unsigned char*)(0x36))


#endif /* MEMORYMAP_H_ */