#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
bool is_ascii1(const char str[],size_t size)
{
    
    if (size == 0)
	return false;
    for (int i = 0;i < size;i++) {
	if (str[i] == '\0')/*to avoid we set size a negative number,which will map into an extreme big number so we will read illegal area*/
            break;    
        if (str[i] & 0x80) 
	    return false;
    }
    return true;
}
bool is_ascii(const char str[],size_t size)
{
    if (size == 0)
	    return false;
    int i;
    while ((i+8) <= size) {
        uint64_t temp; /*using a bigger type to store char of str,rather than declare an array*/
	memcpy(temp,str[i],8);
	if (temp & 0x8080808080808080)
		return false;
	i += 8;
    }
    while (i < size) {
	if (str[i] & 0x80)
            return false;
	i++;
   
    }
    return true;
}


int main()
{
    char a[] = "abcdefghijk";
    int i;
    i = is_ascii1(a,-1);
    printf("%d\n",i);
}
