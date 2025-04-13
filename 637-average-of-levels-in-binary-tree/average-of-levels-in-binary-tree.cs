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
    public IList<double> AverageOfLevels(TreeNode root) {
        IList<double> res = new List<double>();
        Queue<TreeNode> qNode = new Queue<TreeNode>();
        qNode.Enqueue(root);
        while(qNode.Count > 0){
            double sum = 0;
            int cnt = qNode.Count;
            for(int i = 0; i < cnt; i++){
                TreeNode tmpNode = qNode.Dequeue();
                sum += tmpNode.val;
                if(tmpNode.left != null) qNode.Enqueue(tmpNode.left);
                if(tmpNode.right != null) qNode.Enqueue(tmpNode.right);
            }
            res.Add(sum / cnt);
        }
        return res;
    }
}