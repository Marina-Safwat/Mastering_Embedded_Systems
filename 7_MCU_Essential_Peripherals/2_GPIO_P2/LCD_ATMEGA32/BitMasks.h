/*
 * BitMasks.h
 *
 * Created: 2/14/2024 6:35:33 PM
 *  Author: Marina
 */ 


#ifndef BITMASKS_H_
#define BITMASKS_H_

//bits
#define SETBIT(REG,BIT) REG|=(1<<BIT)
#define CLRBIT(REG,BIT) REG&=~(1<<BIT)
#define TGLBIT(REG,BIT) REG^=(1<<BIT)
#define GETBIT(REG,BIT) ((REG>>BIT)&1)

//nibbles
#define CLR_LOW_NIBBLE(REG) REG&=~(0b1111)
#define CLR_HIGH_NIBBLE(REG) REG&=~(0b1111<<4)
#define SET_LOW_NIBBLE(REG) REG|=(0b1111)
#define SET_HIGH_NIBBLE(REG) REG|=(0b1111<<4)

//SSD->Set Specific Data at that position
#define SSD_HIGH_HIGH_NIBBLE(REG,DATA) CLR_HIGH_NIBBLE(REG); REG|=(DATA & 0xF0);
#define SSD_LOW_HIGH_NIBBLE(REG,DATA) CLR_HIGH_NIBBLE(REG); REG|=(DATA << 4);

#endif /* BITMASKS_H_ */