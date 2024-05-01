/*
 * BitMasks.h
 *
 *  Created on: Apr 22, 2024
 *      Author: Marina
 */

#ifndef INC_BITMASKS_H_
#define INC_BITMASKS_H_

//bits
#define SETBIT(REG,BIT) REG|=(1<<BIT)
#define CLRBIT(REG,BIT) REG&=~(1<<BIT)
#define TGLBIT(REG,BIT) REG^=(1<<BIT)
#define GETBIT(REG,BIT) ((REG>>BIT)&1)

//nibbles
#define CLR_LOW_NIBBLE(REG) 	REG&=~(0b1111)
#define CLR_HIGH_NIBBLE(REG) 	REG&=~(0b1111<<4)
#define SET_LOW_NIBBLE(REG) 	REG|=(0b1111)
#define SET_HIGH_NIBBLE(REG) 	REG|=(0b1111<<4)

//4 BITs
#define CLR_4_BIT(REG,POS) 		REG&=~(0xf<<POS)
#define WRT_4_BIT(REG,VAL,POS) 	REG|=(VAL<<POS)

//port
#define SET_16BIT(REG) REG|=(0xFFFF)
#define GET_16BIT(REG) (REG&0xFFFF)

//SSD->Set Specific Data at that position
#define SSD_HIGH_HIGH_NIBBLE(REG,DATA) CLR_HIGH_NIBBLE(REG); REG|=(DATA & 0xF0);
#define SSD_LOW_HIGH_NIBBLE(REG,DATA) CLR_HIGH_NIBBLE(REG); REG|=(DATA << 4);


#endif /* INC_BITMASKS_H_ */
