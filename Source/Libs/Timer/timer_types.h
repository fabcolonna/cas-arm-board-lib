#ifndef __TIMER_TYPES_H
#define __TIMER_TYPES_H

#include <stdint.h>

#define MR_COUNT 4

enum timer_mr_action
{
    TIM_MR_NOP = 0,
    TIM_MR_INT = 1 << 0,
    TIM_MR_RES = 1 << 1,
    TIM_MR_STP = 1 << 2
};

typedef struct
{
    u8 which;
    u32 match;
    u8 actions;
} TIMER_MatchReg;

typedef struct timer_opaque TIMER;

#endif