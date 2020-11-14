#include <stdint.h>
#include <assert.h>
#include <stdio.h>

typedef struct a {
    uint8_t one;
    uint32_t two; 
} a;

typedef struct b {
    uint8_t one;
    uint8_t two;
    uint8_t thread;
    uint8_t three;
    uint32_t four;

} b;

typedef struct c {
    uint8_t one; // should pad three out
    uint32_t two; 
    uint64_t three;
} c;

typedef struct d {
    uint64_t one;
    uint32_t two;
} d;

int main()
{
    printf("sizeof a: %d, sizeof b: %d\n", (int) sizeof(a), (int) sizeof(b));
    printf("sizeof c: %d\n", (int) sizeof(c));
    printf("sizeof d: %d\n", (int) sizeof(d));
}

