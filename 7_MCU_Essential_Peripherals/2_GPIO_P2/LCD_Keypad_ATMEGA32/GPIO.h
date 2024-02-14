/*
 * GPIO.h
 *
 * Created: 2/14/2024 5:47:25 PM
 *  Author: VTM
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#define PORTA (*(volatile unsigned char*)0x3B)
#define DDRA (*(volatile unsigned char*)0x3A)
#define PINA (*(volatile unsigned char*)0x39)

#define PORTB (*(volatile unsigned char*)0x38)
#define DDRB (*(volatile unsigned char*)0x37)
#define PINB (*(volatile unsigned char*)0x36)

#define PORTD (*(volatile unsigned char*)0x32)
#define DDRD (*(volatile unsigned char*)0x31)
#define PIND (*(volatile unsigned char*)0x30)

#endif /* GPIO_H_ */