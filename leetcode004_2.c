#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int index1, index2, index3, index5, index6, res, resA, resB;
	index1 = index2 = index3 = index5 = index6 = res = resA = resB = 0;
	int length = nums1Size + nums2Size;
	if (length%2!=0) {
		index5 = (length-1)/2;
        index6 = 0;
	}
    else {
    	index5 = res = length/2;
    	index6 = length/2-1;
    }
    for (int i=0;i<length;++i) {
    	if (index1<nums1Size && index2<nums2Size) {
    		if (nums1[index1] < nums2[index2]) res = nums1[index1++];
    		else res = nums2[index2++];
    	}
    	else if (index1<nums1Size) res = nums1[index1++];
    	else res = nums2[index2++];
    	if (i == index5) resA = res;
    	if (i == index6) resB = res;
    }
    return (length%2!=0) ? resA : ((resA + resB)/2.0);
}

int main(int argc, char const *argv[])
{
	int c[2] = {1,3};
	int b[2] = {2};
	double dd = findMedianSortedArrays(c,2,b,1);
	printf("dd:%g\n", dd);
	return 0;
}
