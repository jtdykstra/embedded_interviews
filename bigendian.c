#include <stdio.h>

#define UPPER_BYTE 0xFF000000
#define UPPER_MIDDLE_BYTE 0x00FF0000
#define LOWER_MIDDLE_BYTE 0x0000FF00
#define LOWER_BYTE 0x000000FF

int littleToBig(int little)
{
    int newInt = 0;

    newInt |= (little & UPPER_BYTE) >> 24;
    newInt |= (little & UPPER_MIDDLE_BYTE) >> 8;
    newInt |= (little & LOWER_MIDDLE_BYTE) << 8;
    newInt |= (little & LOWER_BYTE) << 24;

    return newInt;
}

int main()
{
    printf("orig %x\n", 0xAABBCCDD);
    printf("endian swap %x\n", littleToBig(0xAABBCCDD));
}