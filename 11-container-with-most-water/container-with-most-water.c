int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int val = 0, max = 0;
    while(left < right){
        if(height[left] < height[right]){
            val = height[left] * (right - left);
            left++;
        }
        else{
            val = height[right] * (right - left); 
            right--;
        }
        max = val > max ? val : max;
    }
    return max;
}