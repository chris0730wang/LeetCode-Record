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
    
    public int SumOfLeftLeaves(TreeNode root) {
        if(root.left == null && root.right == null) return 0;
        int ret = 0;
        Queue<TreeNode> qNode = new Queue<TreeNode>();
        qNode.Enqueue(root);
        while(qNode.Count > 0){
            TreeNode tmpNode = qNode.Dequeue();
            if(tmpNode.left != null){
                if(tmpNode.left.left == null && tmpNode.left.right == null){
                    ret += tmpNode.left.val;
                }else{
                    qNode.Enqueue(tmpNode.left);
                }
            }
            if(tmpNode.right != null){
                qNode.Enqueue(tmpNode.right);
            }
        }
        return ret;
    }
}