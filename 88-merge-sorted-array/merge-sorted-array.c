int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int idx = 0;
    nums1Size = m + n;
    for(i = m; i < nums1Size; i++){
        nums1[i] = nums2[idx++];
    }
    qsort(nums1, nums1Size, sizeof(int), cmp);
}