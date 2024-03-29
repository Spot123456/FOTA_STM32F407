#include	"STD_types.h"
#include	"Bit_Math.h"

#include	"NVIC_interface.h"
#include	"NVIC_private.h"
#include	"NVIC_config.h"





void		NVIC_voidInit()
{
	/*		How many Groups and Sub Group used in the system	*/
	#ifndef			SCB_AIRCR
		#define		SCB_BASE_ADD		(0xE000ED00)
		#define		SCB_AIRCR			*((u32 *)(SCB_BASE_ADD+0x0C))
	#endif

	SCB_AIRCR = NVIC_NUM_GRP_SUB;
}



void		NVIC_voidEnablePerInt(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ISER0=(1<<IntNum); // m3mlna4 OR(|) 3l4an 0 doesnt effect
	}
	else if (IntNum<64)
	{
		IntNum-=32;
		NVIC_ISER1=(1<<IntNum);
	}
	else { /*do nothing*/ }

}

void		NVIC_voidDisablePerInt(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ICER0=(1<<IntNum); // m3mlna4 OR(|) 3l4an 0 doesnt effect
	}
	else if (IntNum<64)
	{
		IntNum-=32;
		NVIC_ICER1=(1<<IntNum);
	}
	else { /*do nothing*/ }

}

void		NVIC_voidSetPendingFlag(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ISPR0=(1<<IntNum); // m3mlna4 OR(|) 3l4an 0 doesnt effect
	}
	else if (IntNum<64)
	{
		IntNum-=32;
		NVIC_ISPR1=(1<<IntNum);
	}
	else { /*do nothing*/ }

}

void		NVIC_voidClrPendingFlag(u8 IntNum)
{
	if(IntNum<32)
		{
			NVIC_ICPR0=(1<<IntNum); // m3mlna4 OR(|) 3l4an 0 doesnt effect
		}
		else if (IntNum<64)
		{
			IntNum-=32;
			NVIC_ICPR1=(1<<IntNum);
		}
		else { /*do nothing*/ }
}


u8			NVIC_u8ReadActiveFlag(u8 IntNum)
{
	u8 local_val=0;
	if(IntNum<32)
			{
				local_val=( NVIC_ICPR0=(1<<IntNum)); // m3mlna4 OR(|) 3l4an 0 doesnt effect
			}
			else if (IntNum<64)
			{
				IntNum-=32;
				local_val=( NVIC_ICPR1=(1<<IntNum));
			}
			else { /*do nothing*/ }
	return local_val;

}

/*		4 Groups and 4 sub Groups , EXTI0 int Num = 6 ===> Group = 1, Sub = 2 	*/
/*NVIC_voidSetSwIntPriority(6,0b0110);*/

void		NVIC_voidSetSwIntPriority(u8 IntNum , u8 priority)
{
	/*		Range Check			*/
		if(IntNum<32)
		{
			NVIC_IPR[IntNum] = (priority << 4 );
		}

}







