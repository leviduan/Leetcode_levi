#include <stdio.h>
int a[5000];

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;
	while(index1<nums1Size && index2<nums2Size) {
		if (nums1[index1]<nums2[index2]) {
			a[index3++] = nums1[index1++];
		}
		else {
			a[index3++] = nums2[index2++];
		}
	}
	while (index1<nums1Size) {
		a[index3++] = nums1[index1++];
	}
	while (index2<nums2Size) {
		a[index3++] = nums2[index2++];
	}
	if ((index3 % 2) != 0) {
		return a[(index3-1)/2];
	}
	else {
		return (a[index3/2]+a[index3/2-1])/2.0;
	}	
}

int main(int argc, char const *argv[])
{
	int c[2] = {1,3};
	int b[2] = {2};
	double dd = findMedianSortedArrays(c,2,b,1);
	printf("dd:%g\n", dd);
	return 0;
}
