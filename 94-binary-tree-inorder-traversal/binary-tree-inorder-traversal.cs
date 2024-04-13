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

	List<int> ret = new List<int>();
    
	public IList<int> InorderTraversal(TreeNode root) {
		inorder(root);
		return ret;
    }
	
	public void inorder(TreeNode root){
        if(root == null) return;
		if(root.left != null) inorder(root.left);
		ret.Add(root.val);
		if(root.right != null) inorder(root.right);
	}
}