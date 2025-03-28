public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {

        var res = new Dictionary<string, List<string>>();
        foreach(string str in strs){
            int[] count = new int[26];
            foreach(char c in str){
                count[c - 'a']++;
            }
            string key = string.Join(',', count);
            if(!res.ContainsKey(key)){
                res.Add(key, new List<string>());
            }
            res[key].Add(str);
        }
        return res.Values.ToList<IList<string>>();
    }
}