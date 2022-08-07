/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root == null || (root.left == null && root.right == null)) return root;
        TreeNode temp, treenodetoleft = root.left, treenodetoright = root.right, index = root;
        if(treenodetoleft != null || treenodetoright != null){
            temp = index.left;
            index.left = index.right;
            index.right = temp;
            treenodetoleft = index.left;
            treenodetoright = index.right;
            invertTree(treenodetoleft);
            invertTree(treenodetoright);
        }
        return root;
    }
}