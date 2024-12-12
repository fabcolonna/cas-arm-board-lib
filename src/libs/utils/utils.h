#ifndef __UTILS_H
#define __UTILS_H

#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define SET_BIT(reg, bit) (reg |= (1 << bit))
#define CLR_BIT(reg, bit) (reg &= ~(1 << bit))

#define SET_BITS(reg, value, bit) (reg |= ((value) << bit))
#define CLR_BITS(reg, value, bit) (reg &= ~((value) << bit))

#define _USER_EXTERNALLY volatile
#define _DECL_EXTERNALLY extern
#define _INT_HANDLER extern void
#define _INLINE __attribute__((always_inline)) inline
#define _OUT
#define _IN const
#define _NULLABLE

#endif
