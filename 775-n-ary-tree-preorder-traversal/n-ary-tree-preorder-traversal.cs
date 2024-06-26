/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,IList<Node> _children) {
        val = _val;
        children = _children;
    }
}
*/

public class Solution {

	List<int> ret = new List<int>();
    
	public IList<int> Preorder(Node root) {
		dopreorder(root);
		return ret;
    }
	
	public void dopreorder(Node root){
		if(root == null) return;
		ret.Add(root.val);
		foreach(Node node in root.children){
			dopreorder(node);
		}
	}
}