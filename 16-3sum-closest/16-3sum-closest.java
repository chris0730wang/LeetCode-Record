class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int min=Math.abs(target-(nums[0]+nums[1]+nums[nums.length-1])), j, k, answer = nums[0]+nums[1]+nums[nums.length-1];
        for(int i=0; i<nums.length-2; i++){
            j = i+1; k = nums.length-1;
            while(j<k){
                if(Math.abs(target-(nums[i]+nums[j]+nums[k]))<min){
                    min = Math.abs(target-(nums[i]+nums[j]+nums[k]));
                    answer = nums[i]+nums[j]+nums[k];
                }
                if(nums[j]+nums[k]>target-nums[i]) --k;
                else ++j;
            }
        }
        return answer;
    }
}