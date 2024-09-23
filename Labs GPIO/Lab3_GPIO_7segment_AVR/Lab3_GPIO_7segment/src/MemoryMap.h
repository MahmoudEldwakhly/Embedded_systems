/*
 * MemoryMap.h
 *
 * Created: 9/21/2024 6:38:43 PM
 *  Author: Mahmoud Eldawakhly
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_


#define DDRA *((volatile unsigned char *)0x3A)
#define PORTA *((volatile unsigned char *)0x3B)
#define PINA *((volatile unsigned char *)0x39)

#define DDRC *((volatile unsigned char *)0x34)
#define PORTC *((volatile unsigned char *)0x35)
#define PINC *((volatile unsigned char *)0x33)



#endif /* MEMORYMAP_H_ */