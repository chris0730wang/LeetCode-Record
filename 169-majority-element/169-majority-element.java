class Solution {
    public int majorityElement(int[] nums) {
        int len = nums.length;
        int ans = nums[0], fre = 1;

        for (int i = 1; i < len; i++){
            if (nums[i] == ans){
                fre++;
            } else if (fre > 0){
                fre--;
            } else {
                ans = nums[i];
                fre = 1;
            }
        }
        return ans;
    }
}