package leetcode;

// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

public class sorteListToBST {
	private class ListNode {
		int val;
		ListNode next;
		ListNode(int x) { val = x; }
	}
	
	private class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}

    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) return null;
        if (head.next == null) return new TreeNode(head.val);
        ListNode pre = head;
        ListNode p1 = head;
        ListNode p2 = head;
        while(p2 != null && p2.next != null) {
            pre = p1;
            p1 = p1.next;
            p2 = p2.next.next;
        }
        pre.next = null;
        TreeNode result = new TreeNode(p1.val);
        result.left = sortedListToBST(head);
        result.right = sortedListToBST(p1.next);
        return result;
    }
}
