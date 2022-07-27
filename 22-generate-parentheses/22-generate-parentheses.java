class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> answer = new ArrayList<>();
        dfs(n, n, answer, "");
        return answer;
    }
    
    private void dfs(int left, int right, List<String> answer, String s){
        if(left == 0 && right == 0) answer.add(s);
        else{
            if(left > 0) dfs(left-1, right, answer, s+"(");
            if(right > left) dfs(left, right-1, answer, s+")");
        }
        
    }
}