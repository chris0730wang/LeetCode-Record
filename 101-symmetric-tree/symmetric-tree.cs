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
    public bool IsSymmetric(TreeNode root) {
        if(root.left == null && root.right == null) return true;
        Queue<TreeNode> qNode = new Queue<TreeNode>();
        qNode.Enqueue(root.left);
        qNode.Enqueue(root.right);
        while(qNode.Count > 0){
            TreeNode tmpNode1 = qNode.Dequeue();
            TreeNode tmpNode2 = qNode.Dequeue();
            if(tmpNode1 != null && tmpNode2 != null){
                if(tmpNode1.val != tmpNode2.val) return false;
                qNode.Enqueue(tmpNode1.left);
                qNode.Enqueue(tmpNode2.right);
                qNode.Enqueue(tmpNode1.right);
                qNode.Enqueue(tmpNode2.left);
            }
            else if(tmpNode1 == null && tmpNode2 == null){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
}