package ctci;

import java.util.ArrayList;
import java.util.Random;

public class Chapter4 {
	
	// Q 4.2
	
	private class TNode <T>{
		T data;
		TNode<T> parent;
		TNode<T> left;
		TNode<T> right;
		
		public TNode(T data) {
			this.data = data;
			this.left = null;
			this.right = null;
		}
		
		public int depth(){
			int depth = 0;
			TNode<T> node = this;
			while (node.parent != null) {
				node = node.parent;
				depth++;
			}
			return depth;
		}
	}
	
	public TNode<Integer> MinimalBST(int[] sorted_elements){
		return MinimalBST (sorted_elements, 0, sorted_elements.length-1);
	}
	
	public TNode<Integer> MinimalBST(int[] sorted_elements, int start, int end){
		if (start == end) {
			return new TNode<Integer>(sorted_elements[0]);
		}
		int mid = (start + end)/2;
		TNode<Integer> bn = new TNode<Integer>(sorted_elements[mid]);
		bn.left = MinimalBST(sorted_elements, start, mid-1);
		bn.left = MinimalBST(sorted_elements, mid+1, end);
		return bn;
	}

	// Q 4.3
	private class Node {
		int data;
		Node next;
		
		public Node(int d){
			data = d;
			next = null;
		}
		
		public void appendToTail(int d){
			Node end = new Node(d);
			Node head = this;
			while (head.next != null){
				head = head.next;
			}
			head.next = end;
		}
	}
	
//	public ArrayList<Node> listOfDepths(){
//		MyQueue<Node> queue = new MyQueue<Node>();
//	}

	// Q 4.5
	public Boolean checkBST(TNode<Integer> bt) {
		return checkBST(bt, null, null);
	}

	public boolean checkBST(TNode<Integer> bt, Integer min, Integer max) {
		if (bt == null) {
			return true;
		}
		if ((min != null && bt.data < min) || (max != null && bt.data > max)) {
			return false;
		}
		if (!checkBST(bt.left, min, bt.data) || !checkBST(bt.right, bt.data, max)) {
			return false;
		}
		return true;
	}
	
	// Q 2.6
	
	public TNode<Integer> successor(TNode<Integer> bn){
		if (bn.right != null) {
			bn = bn.right;
			while (bn.left != null) {
				bn = bn.left;
			}
			return bn;
		} else {
			while (bn.parent != null && bn.parent.left!=bn) {
				bn = bn.parent;
			}
			return bn.parent;
		}
	}
	
	// Q 4.8
	public TNode<Integer> commonAncestor(TNode<Integer> p, TNode<Integer> q) {
		int d = p.depth() - q.depth();
		TNode<Integer> n = d > 0 ? q : p;
		TNode<Integer> deeper = d > 0 ? p : q;
		for (int i = 0 ; i < d; i++){
			deeper = deeper.parent;
		}
		while (n != deeper && n != null && deeper != null) {
			n = n.parent;
			deeper = deeper.parent;
		}
		return n == null || deeper == null ? null : n;
	}
	
	// Q 4.10
	
	public void getPreOrderString(TNode<Integer> tn, String s){
		if (tn == null) {
			s += 'X';
			return;
		}
		s += tn.data;
		getPreOrderString(tn.left, s);
		getPreOrderString(tn.right, s);
	}
	
	public boolean containsTree(TNode<Integer> t1, TNode<Integer> t2) {
		String s1 = "";
		String s2 = "";
		getPreOrderString(t1, s1);
		getPreOrderString(t2, s2);
		if (s1.indexOf(s2) != -1) return true;
		else return false;
	}
	
	public boolean containsTreeA(TNode<Integer> t1, TNode<Integer> t2) {
		if (t2 == null) return true;
		else return subTree(t1, t2);
	}
	
	public boolean subTree(TNode<Integer> t1, TNode<Integer> t2) {
		if (t1 == null) return false;
		else if (t1.data == t2.data && matchTree(t1, t2)) return true;
		else return subTree(t1.left, t2) || subTree(t1.right, t2);
	}
	
	public boolean matchTree(TNode<Integer> t1, TNode<Integer> t2) {
		if (t1 == null && t2 == null) return true;
		return t1.data == t2.data && matchTree (t1.left, t2.left)
				&& matchTree (t1.right, t2.right);
	}
	
	// Q 2.11
	class BSTNode {
		private int data;
		public int size;
		public BSTNode left;
		public BSTNode right;
		
		public BSTNode(int d) {
			data = d;
			size = 1;
		}
		
		public BSTNode getRandomNode() {
			int leftSize = this.left != null ? this.left.size : 0;
			Random rand = new Random();
			int idx = rand.nextInt(this.size);
			if (idx < leftSize) {
				return this.left.getRandomNode();
			} else if (idx == leftSize) {
				return this;
			} else {
				return this.right.getRandomNode();
			}
		}
		
		public void insert(int d) {
			if (d <= this.data) {
				if (this.left == null) {
					BSTNode tn = new BSTNode(d);
					this.left = tn;
					return;
				} else {
					this.left.insert(d);
				}
			} else {
				if (this.right == null) {
					BSTNode tn = new BSTNode(d);
					this.right = tn;					
				} else {
					this.right.insert(d);
				}
			}
			this.size++;
		}
		
		public BSTNode find(int d) {
			if (this.data == d) return this;
			else {
				if (d <= this.data) {
					if (this.left == null) return null;
					else return this.left.find(d);
				} else {
					if (this.right == null) return null;
					else return this.right.find(d);
				}
			}
		}
		
		public BSTNode findParent(int d) {
			if ((this.left != null && this.left.data == d)
					|| (this.right != null && this.right.data == d))
				return this;
			else {
				if (d <= this.data) {
					if (this.left == null) return null;
					else return this.left.findParent(d);
				} else {
					if (this.right == null) return null;
					else return this.right.findParent(d);
				}
			}
		}
		
		public boolean hasNoChild() {
			if (this.left == null && this.right == null) return true;
			else return false;
		}
		
		public boolean hasBothChildren() {
			if (this.left != null && this.right != null) return true;
			else return false;
		}
		
		public BSTNode getOneChild() {
			if (this.left != null && this.right != null) return null;
			return this.left != null ? this.left : this.right;
		}
		
		public void delete(BSTNode root, int d) {
			BSTNode parent = findParent(d);
			BSTNode n;
			if (parent == null) {
				if (root.data != d) return; // not found
				else n = root;
			} else{
				n = parent.left.data == d ? parent.left : parent.right;
			}
			BSTNode next;
			if (n.hasNoChild()) {
				next = null;
			} else {
				if (n.hasBothChildren()) {
					next = deleteAdjust(n.right);
				} else {
					next = n.getOneChild();
				}
			}
			if (root.data == d) {
				if (next != null) {
					root.data = next.data;
					root.size--;
				}
				else root = null;
			} else if (parent.left.data == d) {
				BSTNode temp = parent.left;
				parent.left = next;
				next.left = temp.left;
				next.right = temp.right;
				parent.size--;
			} else {
				BSTNode temp = parent.right;
				parent.right = next;
				next.left = temp.left;
				next.right = temp.right;
				parent.size--;
			}
		}
		
		public BSTNode deleteAdjust(BSTNode bt) {
			if (bt.left == null) {
				return bt;
			}
			BSTNode adj = deleteAdjust(bt.left);
			if (adj == bt.left) {
				bt.left = null;
			}
			return adj;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
