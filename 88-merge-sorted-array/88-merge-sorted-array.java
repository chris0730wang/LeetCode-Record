class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
    
        int index = 0, min, temp;
        for(int i=m; i<m+n; i++){
            nums1[i] = nums2[index];
            index++;
        }
        for(int i=0; i<m+n-1; i++){
            min = nums1[i];
            index = i;
            for(int j=i+1; j<m+n; j++){
                if(nums1[j] < min){
                    index = j;
                    min = nums1[j];
                }
            }
            temp = nums1[i];
            nums1[i] = nums1[index];
            nums1[index] = temp;
        }
    }
}