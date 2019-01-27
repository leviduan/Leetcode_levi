/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b; //由小到大排序
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int **returnArray = (int**)malloc(sizeof(int *) * (numsSize*(numsSize-1)*(numsSize-2))/6);  
    if (numsSize < 3) {
        *returnSize = 0;
        return returnArray;
    }
    int top = 0;
    int pre = nums[0];
    for(int i=0;i<numsSize-2;++i) {
        if (i>0 && nums[i] == nums[i-1]) continue;
        if (nums[i] > 0) break;
        int index = numsSize-1;
        for(int j=i+1;j<numsSize-1;++j) {
            if (index <= j) break;
            if (j>i+1 && nums[j] == nums[j-1]) continue;
            int res = 0 - nums[i] - nums[j];
            if (res == nums[index]) {
                returnArray[top] = (int*)malloc(3*sizeof(int));
                returnArray[top][0] = nums[i];
                returnArray[top][1] = nums[j];
                returnArray[top][2] = nums[index];
                ++top;
            }
            else if (res < nums[index]) {
                --index;
                while (index > j) {
                    int res = 0 - nums[i] - nums[j];
                    if (res == nums[index]) {
                        returnArray[top] = (int*)malloc(3*sizeof(int));
                        returnArray[top][0] = nums[i];
                        returnArray[top][1] = nums[j];
                        returnArray[top][2] = nums[index];
                        ++top;
                        break;
                    }
                    else if (res < nums[index]){
                        --index;
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                continue;
            }
        }
    }
    *returnSize = top;
    return returnArray;
}


/*
  Runtime: 48 ms, faster than 100.00% of C online submissions for 3Sum.
*/
