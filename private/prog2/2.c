#include <stdio.h>

#ifdef LITTLE
typedef struct
{
    unsigned b0: 8, b1: 8;
} word_bytes;

typedef struct
{
    unsigned b0: 1, b1: 8;
} word_bits;

#endif

#ifndef LITTLE
typedef struct{

unsigned b3: 8, b2: 8;

} word_bytes;

typedef struct{

unsigned b31: 1, b30: 8;

} word_bits;
#endif