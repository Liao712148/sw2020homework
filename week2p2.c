#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
uint8_t hexchar2val(uint8_t in)
{
    const uint8_t letter = in & 0x40;
    const uint8_t shift = letter >> 3 | letter >> 6;
    return (in + shift) & 0x0f;
}
uint64_t hexstring2val(const char str[])
{
    int len = strlen(str);
    uint64_t result = 0;
    assert(str[0] == '0' && (str[1] == 'x' || str[1] == 'X'));
    
    for (int i = 2;i < len; i++) {
        uint64_t letter = str[i] & 0x40;
	uint64_t shift = (letter >> 3) | (letter >> 6);
	result = result << 4 | ((str[i] + shift) & 0xf);
	}
    return result;
    
}

int main()
{
	char a[] = "0xDEADBEAF";
	printf("%ld \n",hexstring2val(a));
	return 0;
}

