

int removeElement(int* nums, int numsSize, int val){
    int j=0,temp=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]!=val)
        {
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            j++;
        }
    }
    return j;
}