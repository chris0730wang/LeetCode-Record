public class Solution {
    public int LongestConsecutive(int[] nums) {
        HashSet<int> numSet = new HashSet<int>(nums);
        int longest = 0;

        foreach (int num in numSet) {
            if (!numSet.Contains(num - 1)) {
                int len = 1, tmp = num;
                while(numSet.Contains(++tmp)){
                    len++;
                }
                longest = len > longest ? len : longest;
            }
        }
        return longest; 
    }
}