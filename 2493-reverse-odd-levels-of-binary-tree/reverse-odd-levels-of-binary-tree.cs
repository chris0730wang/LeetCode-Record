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
    public TreeNode ReverseOddLevels(TreeNode root) {
        dfs(root.left, root.right, 1);
        return root;
    }
    public void dfs(TreeNode node1, TreeNode node2, int level){
        if(node1 == null || node2 == null) return;

        if(level % 2 == 1){
            int tmp = node1.val;
            node1.val = node2.val;
            node2.val = tmp;
        }

        dfs(node1.left, node2.right, level + 1);
        dfs(node2.left, node1.right, level + 1);
    }
}