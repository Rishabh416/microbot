#include "servoPair.h"

void ServoPair_init(ServoPair *pair, uint32_t chA, uint32_t chB) {
    pair->servoA_channel = chA;
    pair->servoB_channel = chB;
}

void ServoPair_set(ServoPair *pair, uint16_t angleA, uint16_t angleB) {
    __HAL_TIM_SET_COMPARE(&htim2, pair->servoA_channel, (14.4*angleA) + 480);
    __HAL_TIM_SET_COMPARE(&htim2, pair->servoB_channel, (14.4*angleB) + 480);
}
