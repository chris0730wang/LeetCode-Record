public class Solution {
    public int[] Intersection(int[] nums1, int[] nums2) {
        Array.Sort(nums1);
        Array.Sort(nums2);
        List<int> ret = new List<int>();
        int l = 0, r = 0;
        while(l < nums1.Length && r < nums2.Length){
            if(nums1[l] == nums2[r]){
                if(!ret.Contains(nums1[l])) {
                    ret.Add(nums1[l]);
                }
                l++;
                r++;
            }
            else if(nums1[l] < nums2[r]){
                l++;
            }
            else{
                r++;
            }
        }
        return ret.ToArray();
    }
}