#include <stdio.h>
#include <stdint.h>
const uint32_t D = 3;
#define M ((uint64_t)(UINT64_C(0xffffffffffffffff)/(D)+1))
uint32_t quickmod(uint32_t n) {
    uint64_t quotient = ((__uint128_t) M * n) >> 64;
    return n - quotient * D;
}
int main()
{
    printf("%ld",quickmod(5));
    return 0;
}
