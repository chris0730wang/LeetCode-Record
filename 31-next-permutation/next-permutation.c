int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

void nextPermutation(int* nums, int numsSize) {
    for(int i = numsSize - 1; i > 0; i--){
        if(nums[i - 1] < nums[i]){
            for(int j = numsSize - 1; j >= i; j--){
			    if(nums[j] > nums[i - 1]){
				    int tmp1 = nums[i - 1];
				    nums[i - 1] = nums[j];
                    nums[j] = tmp1;
                    qsort(nums + i, numsSize - i, sizeof(int), cmp);
				    return;
			    }
		    }
        }
		
	}
	qsort(nums, numsSize, sizeof(int), cmp);
}