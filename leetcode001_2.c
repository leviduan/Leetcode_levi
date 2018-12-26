#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct object {
	int value;
	int index;
};

int compare(const void *a, const void *b) {
	return ((struct object *)a)->value - ((struct object *)b)->value;
}

int* twoSum(int* nums, int numsSize, int target) {
	int *a = malloc(2 * sizeof(int));
	a[0] = 0;
	a[1] = 0;

	struct object *objectArray = malloc(numsSize * sizeof(struct object));
	for (int i = 0; i < numsSize; ++i) {
		objectArray[i].value = nums[i];
		objectArray[i].index = i;
	}
	qsort(objectArray, numsSize, sizeof(struct object), compare);
	int i = 0;
	int n = numsSize-1;
	while (n > i) {
		int diff = target - objectArray[0].value;
		if (objectArray[n].value > diff) {
			--n;
			continue;
		}
		break;
	}
	int j = 0;
	j = n;
	while (i<j) {
		int diff = target - objectArray[i].value;
		if (diff < objectArray[j].value) {
			--j;
		}
		else if (diff > objectArray[j].value) {
			j=n;
			++i;
		}
		else {
			a[0] = objectArray[i].index;
			a[1] = objectArray[j].index;
			return a;
		}
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	int t[3]  = {5,5};
	int *a = twoSum(t, 2, 10);
	printf("a:%d,%d\n", a[0], a[1]);
	return 0;
}