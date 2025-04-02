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
    public IList<IList<int>> LevelOrder(TreeNode root) {
        IList<IList<int>> ret = new List<IList<int>>();
        if(root == null) return ret;
        Queue<TreeNode> qNode = new Queue<TreeNode>();
        qNode.Enqueue(root);
        while(qNode.Count > 0){
            List<int> tmp = new List<int>();
            int size = qNode.Count;
            for(int i = 0; i < size; i++){
                TreeNode tmpNode = qNode.Dequeue();
                tmp.Add(tmpNode.val);
                if(tmpNode.left != null) qNode.Enqueue(tmpNode.left);
                if(tmpNode.right != null) qNode.Enqueue(tmpNode.right);
            }
            ret.Add(tmp);
        }
        return ret;
    }
}