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
    public IList<IList<int>> LevelOrderBottom(TreeNode root) {
        IList<IList<int>> lstResult = new List<IList<int>>();
        IList<IList<int>> lstRes = new List<IList<int>>();
        if(root == null) return lstRes;
        Queue<TreeNode> qNode = new Queue<TreeNode>();
        qNode.Enqueue(root);
        while(qNode.Count > 0){
            List<int> lstTemp = new List<int>();
            int cnt = qNode.Count;
            for(int i = 0; i < cnt; i++){
                TreeNode tmpNode = qNode.Dequeue();
                if(tmpNode.left != null) qNode.Enqueue(tmpNode.left);
                if(tmpNode.right != null) qNode.Enqueue(tmpNode.right);
                lstTemp.Add(tmpNode.val);
            }
            lstResult.Add(lstTemp);
        }
        for(int i = lstResult.Count - 1; i >= 0; i--){
            lstRes.Add(lstResult[i]);
        }
        return lstRes;
    }
}