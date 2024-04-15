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
        List<double> ret = new List<double>();
        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        while(queue.Count > 0){
            int size = queue.Count;
            double sum = 0.0;
            for(int i = 0; i < size; i++){
                var levelNode = queue.Dequeue();
                sum += levelNode.val;
                if(levelNode.left != null) queue.Enqueue(levelNode.left);
                if(levelNode.right != null) queue.Enqueue(levelNode.right);
            }
            ret.Add(sum/size);
        }
        
        return ret;
    }
}