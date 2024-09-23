/*
 * utilis.h
 *
 *	
 *  Author: Mahmoud Eldawakhly
 */ 


#ifndef UTILIS_H_
#define UTILIS_H_

#define SetBit(reg,bit)   (reg = reg|(1<<bit))
#define ClearBit(reg,bit) (reg = reg&~(1<<bit))
#define ReadBit(reg,bit)  ((reg >> bit) & 1)
#define ToggleBit(reg,bit) (reg = reg^(1<<bit))




#endif /* UTILIS_H_ */