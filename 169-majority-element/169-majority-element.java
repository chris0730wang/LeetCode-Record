class Solution {
    public int majorityElement(int[] nums) {
        int len = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int n: nums){
            System.out.println(n);
            int cur = map.getOrDefault(n, 0) + 1;
            if (cur > (len >> 1)){
                return n;
            }
            map.put(n, cur);
        }
        return -1;
    }
}