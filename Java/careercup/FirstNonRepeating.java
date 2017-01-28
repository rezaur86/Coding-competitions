package careercup;

import java.util.*;

public class FirstNonRepeating {
	
	public static Character findFirstNonRepeating(String s) {
		LinkedHashSet<Character> lhs = new LinkedHashSet<Character>();
		HashMap <Character, Integer> h = new HashMap <Character, Integer>();
		int rank = 0;
		for (char ch: s.toCharArray()) {
			if (h.get(ch) != null) {
				int x = h.get(ch);
				h.put(ch, ++x);
				lhs.remove(ch);
			} else {
				h.put(ch, ++rank);
				lhs.add(ch);
			}
		}
		return lhs.isEmpty() ?  null : (Character)lhs.toArray()[0];
	}
	
	public static boolean isMatch(String s, String p) {
		int i = 0;
		int idx = 0;
		while (idx < s.length() && i < p.length()){
			char ch = s.charAt(idx);
			if (ch == p.charAt(i) || p.charAt(i) == '.') {
				i++;
				if (i < p.length() && p.charAt(i) == '*') {
					i--;
				}
				idx++;
			} else if (i + 1 < p.length() && p.charAt(i+1) == '*') {
				i += 2;
			}
			else return false;
		}
		return idx < s.length() || (i < p.length() && p.charAt(p.length()-1) != '*')? false : true;
	}

	public static int pMean(int[] nums) {
		int[] pMeans = new int[nums.length];
		int n = nums.length;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			pMeans[0] += (i+1)*nums[i];
			sum += nums[i];
		}
		for (int i = 1; i < n; i++) {
			pMeans[i] = pMeans[i-1] + sum - (n-i+1)*nums[n-i];
		}
		java.util.Arrays.sort(pMeans);
		return pMeans[nums.length-1];
	}

	private class TreeNode <T> {
		public T data;
		public boolean traversed;
		public TreeNode<T> left;
		public TreeNode<T> right;
		
		public TreeNode (T d){
			data = d;
			traversed = false;
		}
	}
	
	public static char maxDepth(TreeNode<Character> tn) {
		Queue<TreeNode<Character>> q = new LinkedList<TreeNode<Character>>();
		tn.traversed = true;
		q.add(tn);
		char lastChar = tn.data;
		while (!q.isEmpty()) {
			TreeNode<Character> n = q.poll();
			if (!n.left.traversed) {
				n.left.traversed = true;
				q.add(n.left);
			}
			if (!n.right.traversed) {
				n.right.traversed = true;
				q.add(n.right);
			}
			lastChar = n.data;
		}
		return lastChar;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(FirstNonRepeating.findFirstNonRepeating("aafddssddss"));
		System.out.println(FirstNonRepeating.isMatch("aa", "a"));
		System.out.println(FirstNonRepeating.isMatch("aa", "aa"));
		System.out.println(FirstNonRepeating.isMatch("aaa", "aa"));
		System.out.println(FirstNonRepeating.isMatch("aa", "a*"));
		System.out.println(FirstNonRepeating.isMatch("aa", ".*"));
		System.out.println(FirstNonRepeating.isMatch("ab", ".*"));
		System.out.println(FirstNonRepeating.isMatch("aab", "c*a*b*"));
		System.out.println(FirstNonRepeating.isMatch("ccca", "c*ab"));
		int[] nums = {20, 30, 10};
		System.out.println(FirstNonRepeating.pMean(nums));
	}

}
