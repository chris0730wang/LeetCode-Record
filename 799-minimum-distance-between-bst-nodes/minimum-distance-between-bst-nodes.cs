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
    public int MinDiffInBST(TreeNode root) {
        int min = -1;
        List<int> lstVal = new List<int>();
        Queue<TreeNode> qNode = new Queue<TreeNode>();
        qNode.Enqueue(root);
        while(qNode.Count > 0){
            TreeNode tmpNode = qNode.Dequeue();
            if(tmpNode != null){
                foreach(int val in lstVal){
                    if(Math.Abs(tmpNode.val - val) < min || min < 0) min = Math.Abs(tmpNode.val - val);
                }
                lstVal.Add(tmpNode.val);
                qNode.Enqueue(tmpNode.left);
                qNode.Enqueue(tmpNode.right);
            }
        }
        return min;
    }
}