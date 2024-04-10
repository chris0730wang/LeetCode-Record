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
    List<TreeNode> lstTmp = new List<TreeNode>();
    public TreeNode IncreasingBST(TreeNode root) {
        inorder(root);
        for(int i = 0; i < lstTmp.Count() - 1; i++){
            lstTmp[i].left = null;
            lstTmp[i].right = lstTmp[i + 1];
        }
        lstTmp[lstTmp.Count() - 1].left = null;
        lstTmp[lstTmp.Count() - 1].right = null;
        return lstTmp[0];
    }
    void inorder(TreeNode root){
        if(root == null) return;
        inorder(root.left);
        lstTmp.Add(root);
        inorder(root.right);
    }
}