#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
const uint32_t D = 3;

#define M ((uint64_t)(UINT64_C(0xffffffffffffffff)/(D)+1))
bool divisible(uint32_t n) {
	return n * M <= M-1;
}
int main()
{
    printf("%d\n",divisible(5));
    return 0;

}
