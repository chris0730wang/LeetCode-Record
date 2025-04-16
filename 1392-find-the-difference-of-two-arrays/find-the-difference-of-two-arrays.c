/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool isExist(int* nums, int numsSize, int target){
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == target) return true;
    }
    return false;
}

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    int* unique1 = (int*)malloc(sizeof(int) * nums1Size);
    int* unique2 = (int*)malloc(sizeof(int) * nums2Size);
    int size1 = 0, size2 = 0;

    for(int i = 0; i < nums1Size; i++){
        if(!isExist(nums2, nums2Size, nums1[i]) && !isExist(unique1, size1, nums1[i])){
            unique1[size1++] = nums1[i];
        }
    }

    for(int i = 0; i < nums2Size; i++){
        if(!isExist(nums1, nums1Size, nums2[i]) && !isExist(unique2, size2, nums2[i])){
            unique2[size2++] = nums2[i];
        }
    }

    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2);
    (*returnColumnSizes)[0] = size1;
    (*returnColumnSizes)[1] = size2;

    int** res = (int**)malloc(sizeof(int*) * (*returnSize));
    res[0] = unique1;
    res[1] = unique2;

    return res;
}