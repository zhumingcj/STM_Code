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
** Descriptions:		LED?y?��
**--------------------------------------------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

/***************************************************************************************************
 * ?��  ��? : 3?��??���̣�???��????D1?��D2?��D3?��D4��?��y??PG6?��PA8?��PB8?��PB9��?2��4??��??��LED��?3?��?���䨬?����???a?��?e
 * 2?  ��y : ?T
 * ����???�� : ?T
 **************************************************************************************************/
void leds_init(void)
{
   //?����?IO3?��??��?????��11��?
   GPIO_InitTypeDef  GPIO_InitStructure;
   //�䨰?aPA  PB  PG???������?��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOG, ENABLE);	 
	 
	 //????��?IO��?PG6
   GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;	
	 //IO?��?��?��?a50MHz
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	 //?????a��?������?3?
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	 //????IO
   GPIO_Init(GPIOG, &GPIO_InitStructure);	
	
	
	 //????��?IO��?PA8
   GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;
	 //IO?��?��?��?a50MHz
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	 //?????a��?������?3?
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
	 //????IO
   GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	 //????��?IO��?PB8?��PB9
   GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8 | GPIO_Pin_9;	
   //IO?��?��?��?a50MHz
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	 //?????a��?������?3?
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	 //????IO
   GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
   //����??D1?��D2?��D3?��D43?��??�����䨬??a?��?e	
	 leds_off();					
}
/***************************************************************************
 * ?��  ��? : ��?����?a�����?��?��?4????��?��?(D1 D2 D3 D4)
 * 2?  ��y : ?T
 * ����???�� : ?T
 ***************************************************************************/
void leds_on(void)
{
   //LED??��?��?D1��?��y??(PG6)��?3?�̨���???��??���?����D1
   GPIO_ResetBits(GPIOG,GPIO_Pin_6);
   //LED??��?��?D2��?��y??(PA8)��?3?�̨���???��??���?����D2
	 GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	 //LED??��?��?D3?��D4��?��y??(PB8 PB9)��?3?�̨���???��??���?����D3?��D4
	 GPIO_ResetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9);
}

/***************************************************************************
 * ?��  ��? : ?��?e?a�����?��?��?4????��?��?(D1 D2 D3 D4)
 * 2?  ��y : ?T
 * ����???�� : ?T
 ***************************************************************************/
void leds_off(void)
{
   //LED??��?��?D1��?��y??(PG6)��?3???��???��??��?��?eD1
   GPIO_SetBits(GPIOG,GPIO_Pin_6);
   //LED??��?��?D1��?��y??(PA8)��?3???��???��??��?��?eD2
	 GPIO_SetBits(GPIOA,GPIO_Pin_8);
	 //LED??��?��?D1��?��y??(PB8 PB9)��?3???��???��??��?��?eD3 D4
	 GPIO_SetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9);
}

/***************************************************************************
 * ?��  ��? : ��?������??????����?LED
 * 2?  ��y : [IN]led_idx:LED ??��|��?��y??����o?
 * ����???�� : ?T
 ***************************************************************************/
void led_on(uint32_t led_idx)
{
   //��?��?��y??��?����o?
	 uint16_t pin_num = (uint16_t)(led_idx&0xFFFF);
	 //??��?��y?Y???����?2��?y?��pin_num??��|��?��y??��?3?�̨���???��??���?����??��|��?LED
	 if(led_idx == LED_1)GPIOG->BRR = pin_num;
	 if(led_idx == LED_2)GPIOA->BRR = pin_num;
	 if((led_idx == LED_3) || (led_idx == LED_4))
	 {
		  GPIOB->BRR = pin_num;
	 }
}

/***************************************************************************
 * ?��  ��? : ?��?e��??????����?LED
 * 2?  ��y : [IN]led_idx:LED ??��|��?��y??����o?
 * ����???�� : ?T
 ***************************************************************************/
void led_off(uint32_t led_idx)
{
   //��?��?��y??��?����o?
	 uint16_t pin_num = (uint16_t)(led_idx&0xFFFF);
	 //??��?��y?Y???����?2��?y?��pin_num??��|��?��y??��?3???��???��??��?��?e??��|��?LED
	 if(led_idx == LED_1)GPIOG->BSRR = pin_num;
	 if(led_idx == LED_2)GPIOA->BSRR = pin_num;
	 if((led_idx == LED_3) || (led_idx == LED_4))
	 {
		   GPIOB->BSRR = pin_num;
	 }
}

/***************************************************************************
 * ?��  ��? : ��-��a��??????����?LED��?���䨬?
 * 2?  ��y : [IN]led_idx:LED ??��|��?��y??����o?
 * ����???�� : ?T
 ***************************************************************************/
void led_toggle(uint32_t led_idx)
{
   //��?��?��y??��?����o?
	 uint16_t pin_num = (uint16_t)(led_idx&0xFFFF);
	
	 //??��?��y?Y???����?����1y??ODR??��??��?����|��???����?��????��-��a??��|��?IO��?3?���䨬?
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



