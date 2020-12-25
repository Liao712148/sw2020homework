#include <stdio.h>
#include <string.h>

int SingleNumber(int *nums, int numSize)
{
    int ones = 0, two = 0;
    for (int i = 0; i < numSize; i++) {
	    ones = (ones ^ nums[i]) & ~two;
	    two = (two ^ nums[i]) & ~ones;
    }
    return ones;
