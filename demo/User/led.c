/****************************************Copyright (c)****************************************************
**                                        
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:		 main.c
** Last modified Date:          
** Last Version:		   
** Descriptions:		   
**				
**--------------------------------------------------------------------------------------------------------
** Created by:			FiYu
** Created date:		2018-1-20
** Version:			    1.0
** Descriptions:		LED?y?¡¥
**--------------------------------------------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

/***************************************************************************************************
 * ?¨¨  ¨º? : 3?¨º??¡¥¦Ì£¤???¨²????D1?¡éD2?¡éD3?¡éD4¦Ì?¨°y??PG6?¡éPA8?¡éPB8?¡éPB9¡ê?2¡é4??¨®??¡ìLED¦Ì?3?¨º?¡Á¡ä¨¬?¨¦¨¨???a?¡§?e
 * 2?  ¨ºy : ?T
 * ¡¤¦Ì???¦Ì : ?T
 **************************************************************************************************/
void leds_init(void)
{
   //?¡§¨°?IO3?¨º??¡¥?????¨¢11¨¬?
   GPIO_InitTypeDef  GPIO_InitStructure;
   //¡ä¨°?aPA  PB  PG???¨²¨º¡À?¨®
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOG, ENABLE);	 
	 
	 //????¦Ì?IO¨º?PG6
   GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;	
	 //IO?¨²?¨´?¨¨?a50MHz
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	 //?????a¨ª?¨ª¨¬¨º?3?
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	 //????IO
   GPIO_Init(GPIOG, &GPIO_InitStructure);	
	
	
	 //????¦Ì?IO¨º?PA8
   GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;
	 //IO?¨²?¨´?¨¨?a50MHz
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	 //?????a¨ª?¨ª¨¬¨º?3?
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
	 //????IO
   GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	 //????¦Ì?IO¨º?PB8?¡éPB9
   GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8 | GPIO_Pin_9;	
   //IO?¨²?¨´?¨¨?a50MHz
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	 //?????a¨ª?¨ª¨¬¨º?3?
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	 //????IO
   GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
   //¨¦¨¨??D1?¡éD2?¡éD3?¡éD43?¨º??¡¥¡Á¡ä¨¬??a?¡§?e	
	 leds_off();					
}
/***************************************************************************
 * ?¨¨  ¨º? : ¦Ì?¨¢¨¢?a¡¤¡é¡ã?¨¦?¦Ì?4????¨º?¦Ì?(D1 D2 D3 D4)
 * 2?  ¨ºy : ?T
 * ¡¤¦Ì???¦Ì : ?T
 ***************************************************************************/
void leds_on(void)
{
   //LED??¨º?¦Ì?D1¦Ì?¨°y??(PG6)¨º?3?¦Ì¨ª¦Ì???¡ê??¡ä¦Ì?¨¢¨¢D1
   GPIO_ResetBits(GPIOG,GPIO_Pin_6);
   //LED??¨º?¦Ì?D2¦Ì?¨°y??(PA8)¨º?3?¦Ì¨ª¦Ì???¡ê??¡ä¦Ì?¨¢¨¢D2
	 GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	 //LED??¨º?¦Ì?D3?¡éD4¦Ì?¨°y??(PB8 PB9)¨º?3?¦Ì¨ª¦Ì???¡ê??¡ä¦Ì?¨¢¨¢D3?¡éD4
	 GPIO_ResetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9);
}

/***************************************************************************
 * ?¨¨  ¨º? : ?¡§?e?a¡¤¡é¡ã?¨¦?¦Ì?4????¨º?¦Ì?(D1 D2 D3 D4)
 * 2?  ¨ºy : ?T
 * ¡¤¦Ì???¦Ì : ?T
 ***************************************************************************/
void leds_off(void)
{
   //LED??¨º?¦Ì?D1¦Ì?¨°y??(PG6)¨º?3???¦Ì???¡ê??¡ä?¡§?eD1
   GPIO_SetBits(GPIOG,GPIO_Pin_6);
   //LED??¨º?¦Ì?D1¦Ì?¨°y??(PA8)¨º?3???¦Ì???¡ê??¡ä?¡§?eD2
	 GPIO_SetBits(GPIOA,GPIO_Pin_8);
	 //LED??¨º?¦Ì?D1¦Ì?¨°y??(PB8 PB9)¨º?3???¦Ì???¡ê??¡ä?¡§?eD3 D4
	 GPIO_SetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9);
}

/***************************************************************************
 * ?¨¨  ¨º? : ¦Ì?¨¢¨¢¨°??????¡§¦Ì?LED
 * 2?  ¨ºy : [IN]led_idx:LED ??¨®|¦Ì?¨°y??¡À¨¤o?
 * ¡¤¦Ì???¦Ì : ?T
 ***************************************************************************/
void led_on(uint32_t led_idx)
{
   //¨¨?¦Ì?¨°y??¦Ì?¡À¨¤o?
	 uint16_t pin_num = (uint16_t)(led_idx&0xFFFF);
	 //??¡¤?¨ºy?Y???¨²¡ê?2¡é?y?¡¥pin_num??¨®|¦Ì?¨°y??¨º?3?¦Ì¨ª¦Ì???¡ê??¡ä¦Ì?¨¢¨¢??¨®|¦Ì?LED
	 if(led_idx == LED_1)GPIOG->BRR = pin_num;
	 if(led_idx == LED_2)GPIOA->BRR = pin_num;
	 if((led_idx == LED_3) || (led_idx == LED_4))
	 {
		  GPIOB->BRR = pin_num;
	 }
}

/***************************************************************************
 * ?¨¨  ¨º? : ?¡§?e¨°??????¡§¦Ì?LED
 * 2?  ¨ºy : [IN]led_idx:LED ??¨®|¦Ì?¨°y??¡À¨¤o?
 * ¡¤¦Ì???¦Ì : ?T
 ***************************************************************************/
void led_off(uint32_t led_idx)
{
   //¨¨?¦Ì?¨°y??¦Ì?¡À¨¤o?
	 uint16_t pin_num = (uint16_t)(led_idx&0xFFFF);
	 //??¡¤?¨ºy?Y???¨²¡ê?2¡é?y?¡¥pin_num??¨®|¦Ì?¨°y??¨º?3???¦Ì???¡ê??¡ä?¡§?e??¨®|¦Ì?LED
	 if(led_idx == LED_1)GPIOG->BSRR = pin_num;
	 if(led_idx == LED_2)GPIOA->BSRR = pin_num;
	 if((led_idx == LED_3) || (led_idx == LED_4))
	 {
		   GPIOB->BSRR = pin_num;
	 }
}

/***************************************************************************
 * ?¨¨  ¨º? : ¡¤-¡Áa¨°??????¡§¦Ì?LED¦Ì?¡Á¡ä¨¬?
 * 2?  ¨ºy : [IN]led_idx:LED ??¨®|¦Ì?¨°y??¡À¨¤o?
 * ¡¤¦Ì???¦Ì : ?T
 ***************************************************************************/
void led_toggle(uint32_t led_idx)
{
   //¨¨?¦Ì?¨°y??¦Ì?¡À¨¤o?
	 uint16_t pin_num = (uint16_t)(led_idx&0xFFFF);
	
	 //??¡¤?¨ºy?Y???¨²¡ê?¨ª¡§1y??ODR??¡ä??¡Â?¨¤¨®|¦Ì???¨°¨¬?¨°????¡¤-¡Áa??¨®|¦Ì?IO¨º?3?¡Á¡ä¨¬?
	 if(led_idx == LED_1)
	 {
		 GPIOG->ODR ^= pin_num;
	 }
	 if(led_idx == LED_2)
	 {
		 GPIOA->ODR ^= pin_num;
	 }
	 if((led_idx == LED_3) || (led_idx == LED_4))
	 {
		 GPIOB->ODR ^= pin_num;
	 }
}



