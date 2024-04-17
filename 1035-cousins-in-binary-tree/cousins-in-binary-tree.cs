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
    public bool IsCousins(TreeNode root, int x, int y) {
        List<int> lstVal = new List<int>();
        Queue<TreeNode> qNode = new Queue<TreeNode>();
        qNode.Enqueue(root.left);
        qNode.Enqueue(root.right);
        while(qNode.Count > 0){
            int num = qNode.Count;
            if(lstVal.Contains(x) && lstVal.Contains(y)) return true;
            else if(lstVal.Contains(x) || lstVal.Contains(y)) return false;
            else lstVal.Clear();
            for (int i = 0; i < num; i++){
                TreeNode tmpNode = qNode.Dequeue();
                if(tmpNode != null){
                    if(tmpNode.left != null && tmpNode.right != null){
                        if((tmpNode.left.val == x && tmpNode.right.val == y) || (tmpNode.left.val == y && tmpNode.right.val == x)) return false;
                    }
                    if(tmpNode.left != null){
                        lstVal.Add(tmpNode.left.val);
                        qNode.Enqueue(tmpNode.left);
                    }
                    if(tmpNode.right != null){
                        lstVal.Add(tmpNode.right.val);
                        qNode.Enqueue(tmpNode.right);
                    }
                }
            }
        }
        return false;
    }
}