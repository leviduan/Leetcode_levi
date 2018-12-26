#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target) {
	int *a = malloc(2 * sizeof(int));
	a[0] = 0;
	a[1] = 0;
	for (int i = 0; i < numsSize; ++i) {
		for (int j=i+1;j<numsSize;++j) {
			if (target == (nums[i]+nums[j])) {
				a[0] = i;
				a[1] = j;
				return a;
			}
		}
	}
	return a;
}

int main(int argc, char const *argv[])
{
	int t[3]  = {3,2,3};
	int *a = twoSum(t, 3, 6);
	printf("a:%d,%d\n", a[0], a[1]);
	return 0;
}