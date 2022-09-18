

int minimumSum(int num){
    int *nums = (int*)malloc(sizeof(int) * 4);
    int *temp = nums;
    int i = 0;
    while(num != 0){
        *temp++ = num % 10;
        num /= 10;
    }
    for(int i=0; i<3; i++){
        for(int j=i; j<4; j++){
            if(nums[i] > nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    
    int res = (nums[0] + nums[1]) * 10 + (nums[2] + nums[3]);
    return res;
}