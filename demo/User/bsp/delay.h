#ifndef _DELAY_H
#define _DELAY_H

#include "stm32f10x.h"

//????????
__STATIC_INLINE void sw_delay_us(uint32_t number_of_us);
//????????
__STATIC_INLINE void sw_delay_ms(uint32_t number_of_ms);


__STATIC_INLINE void sw_delay_us(uint32_t number_of_us)
{
  //????????0??,??????  
	if(!number_of_us)
        return;
__asm
    {
loop:
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
		NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    SUBS number_of_us, #1  //number_of_us??
    BNE loop  //???0???LOOP??
    }
}
__STATIC_INLINE void sw_delay_ms(uint32_t number_of_ms)
{
    sw_delay_us(1000*number_of_ms);
}

#endif

