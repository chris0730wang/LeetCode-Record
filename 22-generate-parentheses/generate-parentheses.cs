public class Solution {
    List<string> res = null;
    public List<string> GenerateParenthesis(int n) {
        res = new List<string>();
        helper("", n, n);
        return res;
    }

    public void helper(string curr, int left, int right){
        if(left == 0 && right == 0){
            res.Add(curr);
            return;
        }

        if(left > 0){
            helper(curr + "(", left - 1, right);
        }

        if(right > left){
            helper(curr + ")", left, right - 1);
        }
    }
}