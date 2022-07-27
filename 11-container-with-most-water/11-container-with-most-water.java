class Solution {
    public int maxArea(int[] height) {
        if(height.length<2 || height.length>100000) return 0;
        int N = 0, max = 0;
        for(int i=0; i<height.length; i++){
            for(int j=height.length-1; j>i; j--){
                if(height[i]<=height[j]){
                    N = (j-i) * height[i];
                    if(N>max) max = N;
                    break;
                }
            }
        }
        for(int j=height.length-1; j>=0; j--){
            for(int i=0; i<j; i++){
                if(height[j]<=height[i]){
                    N = (j-i) * height[j];
                    if(N>max) max = N;
                    break;
                }
                
            }
        }
        return max;
    }
}