/*
 * GPIO.h
 *
 * Created: 2/14/2024 6:39:32 PM
 *  Author: Marina
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#define PINA (*(volatile unsigned char*)0x39)
#define DDRA (*(volatile unsigned char*)0x3A)
#define PORTA (*(volatile unsigned char*)0x3B)

#define PINB (*(volatile unsigned char*)0x36)
#define DDRB (*(volatile unsigned char*)0x37)
#define PORTB (*(volatile unsigned char*)0x38)

#endif /* GPIO_H_ */