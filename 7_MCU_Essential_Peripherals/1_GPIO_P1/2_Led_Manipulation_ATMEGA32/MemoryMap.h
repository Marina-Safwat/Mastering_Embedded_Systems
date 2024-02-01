/*
 * MemoryMap.h
 *
 * Created: 2/1/2024 9:27:35 AM
 *  Author: VTM
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

//GPIO Registers

//PortA
#define PORTA (*(volatile unsigned char*)(0x3B))
#define DDRA (*(volatile unsigned char*)(0x3A))
#define PINA (*(volatile unsigned char*)(0x39))

#endif /* MEMORYMAP_H_ */