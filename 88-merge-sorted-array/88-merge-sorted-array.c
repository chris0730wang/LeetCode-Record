

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int index = 0, temp;
    for(int i=m; i<m+n; i++){
        nums1[i] = nums2[index];
        index ++;
    }
    for(int i=1; i<m+n; i++){
        for(int j=i; j>0; j--){
            if(nums1[j] < nums1[j-1]){
                temp = nums1[j-1];
                nums1[j-1] = nums1[j];
                nums1[j] = temp;
            }
        }
    }
}