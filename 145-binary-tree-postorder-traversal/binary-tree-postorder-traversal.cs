/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    List<int> ret = new List<int>();
    public IList<int> PostorderTraversal(TreeNode root) {
        dfs(root);
        return ret;
    }
    public void dfs(TreeNode root){
        if(root == null) return;
        dfs(root.left);
        dfs(root.right);
        ret.Add(root.val);
    }
}