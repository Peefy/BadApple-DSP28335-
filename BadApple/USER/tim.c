
#include "tim.h"

void TIM2_Init_ms(int16 ms)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	ms = RANGE(ms,0,6000);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_TimeBaseStructure.TIM_Period = ms * 10 - 1; // 10ms??
	TIM_TimeBaseStructure.TIM_Prescaler =7200 - 1; //??????TIMx???????????  ???
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //??????:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM??????
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
    
    TIM_Cmd(TIM2,ENABLE);
    
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
    
    TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//

	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ????
	NVIC_Init(&NVIC_InitStructure);	//??
	
	
}

void TIM2_Init(void) //10ms
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_TimeBaseStructure.TIM_Period = 20000 - 1; // 10ms中断
	TIM_TimeBaseStructure.TIM_Prescaler = 36 - 1; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE);
	
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//

	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根�
	
	TIM_Cmd(TIM2,ENABLE);   //使能定时器
		
}
