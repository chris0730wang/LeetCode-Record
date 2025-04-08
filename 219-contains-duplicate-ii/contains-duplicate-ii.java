class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> numsindex = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            if(numsindex.containsKey(nums[i]) && Math.abs(numsindex.get(nums[i]) - i) <= k) return true;
            else numsindex.put(nums[i], i);
        }
        return false;
    }
}