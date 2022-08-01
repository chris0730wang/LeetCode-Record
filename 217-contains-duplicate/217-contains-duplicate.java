class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> hashmap = new HashMap<Integer, Integer>();
        int len = nums.length, times = 0;
        for(int i=0; i<len; i++){
            times = hashmap.getOrDefault(nums[i], 0) + 1;
            if(times >= 2){
                return true;
            }else{
                hashmap.put(nums[i], times);
            }
        }
        return false;
    }
}