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
    public bool FindTarget(TreeNode root, int k) {
        if(root.left == null && root.right == null) return false;

        List<int> lstVal = new List<int>();
        Queue<TreeNode> qNode = new Queue<TreeNode>();

        qNode.Enqueue(root.left);
        qNode.Enqueue(root.right);
        lstVal.Add(root.val);

        while(qNode.Count > 0){
            TreeNode tmpNode = qNode.Dequeue();
            if(tmpNode != null){
                if(lstVal.Contains(k - tmpNode.val)) return true;
                lstVal.Add(tmpNode.val);
                qNode.Enqueue(tmpNode.left);
                qNode.Enqueue(tmpNode.right);
            }
        }

        return false;
    }
}