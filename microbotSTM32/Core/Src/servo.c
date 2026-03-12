#include "../Inc/servo.h"
#include "../Inc/main.h"



extern TIM_HandleTypeDef htim2;

void setServo(int angle) {
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    int dutyCycle = (1000*angle/180) + 1000;
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, dutyCycle);
}