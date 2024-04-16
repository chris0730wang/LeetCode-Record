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
    int ret = 0;
    public int SumOfLeftLeaves(TreeNode root) {
        if(root.left == null && root.right == null) return 0;
        Queue<TreeNode> qNode = new Queue<TreeNode>();
        Queue<TreeNode> qLeft = new Queue<TreeNode>();
        qNode.Enqueue(root);
        while(qNode.Count > 0){
            TreeNode tmpNode = qNode.Dequeue();
            if(tmpNode != null){
                qNode.Enqueue(tmpNode.left);
                qNode.Enqueue(tmpNode.right);
                qLeft.Enqueue(tmpNode.left);
            }
        }
        while(qLeft.Count > 0){
            TreeNode tmpNode = qLeft.Dequeue();
            if(tmpNode != null){
                if(tmpNode.left == null && tmpNode.right == null) ret += tmpNode.val;
            }
        }
        return ret;
    }
}