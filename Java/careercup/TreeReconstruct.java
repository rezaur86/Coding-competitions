package careercup;


public class TreeReconstruct {
	private class TreeNode <T> {
		public T data;
		public TreeNode<T> left;
		public TreeNode<T> right;
		
		public TreeNode (T d){
			data = d;
		}
	}
	
	int preIndex = 0;
	public TreeNode<Character> buildTree(char[] in, char[] pre, int i, int j) {
		if (i > j) return null;
		char pChar = pre[preIndex++];
		TreeNode<Character> tn = new TreeNode<Character>(pChar);
		if (i == j) return tn;
		int inCharIdx = search(in, i, j, pChar);
		if (inCharIdx < 0) return null;
		tn.left = buildTree(in, pre, i, inCharIdx-1);
		tn.right = buildTree(in, pre, inCharIdx+1, j);
		return tn;
	}
	
	public int search(char[] in, int i, int j, char c) {
		for (int x=i; x <= j; x++) {
			if (in[x] == c) return x;
		}
		return -1;
	}
	
	public void printTree(TreeNode<Character> root) {
		if (root != null) {
			printTree(root.left);
			System.out.print(" " + (char) root.data);
			printTree(root.right);
		}
	}
	
	public static void main(String args[]) {
		TreeReconstruct tree = new TreeReconstruct();
        char in[] = new char[]{'D', 'B', 'E', 'A', 'F', 'C'};
        char pre[] = new char[]{'A', 'B', 'D', 'E', 'C', 'F'};
        int len = in.length;
        TreeNode<Character> root = tree.buildTree(in, pre, 0, len - 1);
  
        // building the tree by printing inorder traversal
        System.out.println("Inorder traversal of constructed tree is : ");
        tree.printTree(root);
	}
}
