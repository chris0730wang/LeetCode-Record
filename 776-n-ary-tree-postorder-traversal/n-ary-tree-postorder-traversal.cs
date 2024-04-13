/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, IList<Node> _children) {
        val = _val;
        children = _children;
    }
}
*/

public class Solution {

    public List<int> ret = new List<int>();
	
    public IList<int> Postorder(Node root) {
        dfs(root);
		return ret;
    }
    
	public void dfs(Node root){
		if(root == null) return;
		foreach(Node node in root.children){
			dfs(node);
		}
		ret.Add(root.val);
	}
}