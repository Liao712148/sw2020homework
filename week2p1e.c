#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#define PACKED_BYTE(b) (((uint64_t)b & 0xff) * 0x0101010101010101u)

bool is_alpha(const char *s, size_t size)
{
    if (size == 0)
	return false;
    size_t k = size / 8;
    int i;
    for(i = 0; i < k; i++) {
        uint64_t chunk;
	memcpy(&chunk, s + i * 8, 8);
	uint64_t a = chunk + PACKED_BYTE(128 - 'a' + 0);
	uint64_t A = chunk + PACKED_BYTE(128 - 'A' + 0);
	uint64_t z = chunk + PACKED_BYTE(128 - 'z' - 1);
        uint64_t Z = chunk + PACKED_BYTE(128 - 'Z' - 1);
	uint64_t maskL = (a ^ z) & PACKED_BYTE(0x80);
        uint64_t maskU = (A ^ Z) & PACKED_BYTE(0x80);
	if((maskL | maskU) ^ PACKED_BYTE(0x80))
		return false;
    }
    int temp = k * 8;
    while (temp < size) {
	    if (s[temp] < 65 || (s[temp] > 90 && s[temp] < 97) || s[temp] > 122)
		    return false;
	    temp++;
    }
    return true;
}


int main() 
{
    char a[] = "asdqwerftiqwopeeuriioadsjligayhujik";
    size_t size = strlen(a);
    printf("%d\n",is_alpha(a,size)); 
    return 0;
}
