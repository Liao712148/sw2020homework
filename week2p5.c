#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#define PACKED_BYTE(b) (((uint64_t)(b) & (0xff)) * 0x0101010101010101u)

void strlower_vector(char *s, size_t n)
{
    size_t k = n / 8;
    for (size_t i = 0; i < k;i++, s += 8) {
	   uint64_t *chunk = (uint64_t *) s;
	   if ((*chunk & PACKED_BYTE(0x80)) == 0) {
	       uint64_t A = *chunk + PACKED_BYTE(128 - 'A' + 0);
	       uint64_t Z = *chunk + PACKED_BYTE(128 - 'Z' - 1);
               uint64_t mask = ((A ^ Z) & PACKED_BYTE(0x80)) >> 2;
               *chunk ^= mask;
	   } else
	       tolower(s);
    }
    k = n % 8;
    if (k) 
	 tolower(s);   
}

int main()
{
	char a[] = "Hello SoftWare2020 Fall!!";
       	int n = sizeof(a);
	strlower_vector(a,n);
	puts(a);
	return 0;
}
