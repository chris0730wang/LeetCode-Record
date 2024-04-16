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
    List<int> seenValues = new List<int>();
    public bool FindTarget(TreeNode root, int k) {
        if (root is null) {
            return false;
        }
        if (seenValues.Contains(k-root.val)){
            return true;
        }
        seenValues.Add(root.val);
        return FindTarget(root.left, k) || FindTarget(root.right, k);
    }
}