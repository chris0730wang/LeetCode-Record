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
    public int SumEvenGrandparent(TreeNode root) {
        if(root.left == null && root.right == null) return 0;
        int ret = 0;
        List<TreeNode> lstNode = new List<TreeNode>();
        Queue<TreeNode> qNode = new Queue<TreeNode>();
        if(root.val % 2 == 0) lstNode.Add(root);
        qNode.Enqueue(root.left);
        qNode.Enqueue(root.right);
        while(qNode.Count > 0){
            TreeNode tmpNode = qNode.Dequeue();
            if(tmpNode != null){
                foreach(TreeNode node in lstNode){
                    if(node.left == tmpNode || node.right == tmpNode){
                        if(tmpNode.left != null) ret += tmpNode.left.val;
                        if(tmpNode.right != null) ret += tmpNode.right.val;
                    }
                }
                if(tmpNode.val % 2 == 0) lstNode.Add(tmpNode);
                qNode.Enqueue(tmpNode.left);
                qNode.Enqueue(tmpNode.right);
            }
        }
        return ret;
    }
}