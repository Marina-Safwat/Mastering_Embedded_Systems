/*
 * BitMasks.h
 *
 * Created: 2/1/2024 9:46:06 AM
 *  Author: VTM
 */ 


#ifndef BITMASKS_H_
#define BITMASKS_H_

#define SETBIT(REG,BIT) REG|=(1<<BIT)
#define CLRBIT(REG,BIT) REG&=~(1<<BIT)
#define TGLBIT(REG,BIT) REG^=(1<<BIT)
#define GETBIT(REG,BIT) ((REG>>BIT)&1)

#endif /* BITMASKS_H_ */