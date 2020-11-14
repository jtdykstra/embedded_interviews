#include <stdio.h>
#include <stdint.h>

#define BIT3 (0x1 << 3)

static int a;

void set_bit3(void) {
a |= BIT3;

}

void clear_bit3(void) {
a &= ~BIT3;

}

// Bit tricks
/*
x%10 -> grab last digit
x/10 -> remove last digit
clear lowest bit:
x &= (x-1)
Toggle Bits:
x ^= MASK
Range Masks:
((1<<4)-1)
~((1<<4)-1)
Mask Bit and shift right to get value

Keep in mind sign extension for integers!

reverse bits -> lookup table
*/

/*
    11110000
    l = 00000000
    r = 10000000
    ->
    00001111

    find left bit
    find right bit
    clear bits
    swap bits
*/
#define INT_SIZE 32

/*
    3210
    1010

    swap_bits(, 2,1)

*/
int swap_bits(uint32_t *bits, uint32_t leftBit, uint32_t rightBit)
{
    uint32_t leftValue = (1 << leftBit) & *bits;
    uint32_t rightValue = (1 << rightBit) & *bits;
    printf("left value %x\n", leftValue);
    printf("right value %x\n", rightValue);
    // clear left and right now we've collected them 
    *bits = *bits & ~((1 << leftBit) | (1 << rightBit)); 

    *bits |= leftValue >> (leftBit - rightBit);
    *bits |= rightValue << (leftBit - rightBit);

    return *bits;
}

void reverse_bits(uint32_t *bits)
{
    uint32_t left = 0;
    uint32_t right = 0;

    for (int i = 0; i < INT_SIZE/2; ++i)
    {
        printf("%x\n", *bits);

        swap_bits(bits, INT_SIZE-i-1, i);
    }
}

int main()
{
    a = 0xF;
    printf("a before: %x\n", a);
    clear_bit3();
    printf("a after clearing bit 3: %x\n", a);
    uint32_t bits = 0x00000003;
    printf("orig %x\n", bits);
    printf("swapped %x\n", swap_bits(&bits,31,0));
    uint32_t rev = 0x80000003;
    reverse_bits(&rev);
    printf("reversedd %x\n", rev);
}
