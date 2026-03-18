#ifndef servoPair_H
#define servoPair_H

#include <stdint.h>

typedef struct {
    uint32_t servoA_channel;
    uint32_t servoB_channel;
} ServoPair;

void ServoPair_init(ServoPair *pair, uint32_t chA, uint32_t chB);

void ServoPair_set(ServoPair *pair, uint16_t angleA, uint16_t angleB);

#endif