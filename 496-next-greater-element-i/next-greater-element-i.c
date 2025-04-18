/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int* res = (int*)malloc(sizeof(int) * nums1Size);
    for(int i = 0; i < nums1Size; i++){
        int j = nums2Size - 1;
        int ans = -1;
        while(j >= 0 && nums2[j] != nums1[i]){
            if(nums2[j] > nums1[i]) ans = nums2[j];
            j--;
        }
        res[i] = ans;
    }
    return res;
}