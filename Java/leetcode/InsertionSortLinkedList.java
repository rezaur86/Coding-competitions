package leetcode;

public class InsertionSortLinkedList {
	private class ListNode {
	    int val;
	    ListNode next;
	    ListNode(int x) { val = x; }
	}

    public ListNode insertionSortList(ListNode head) {
        if (head == null) return null;
        if (head.next == null) return head;
        ListNode result = new ListNode(head.val);
        result.next = null;
        while (head.next != null) {
            ListNode iResult = result;
            if (iResult.val > head.next.val) {
                ListNode temp = new ListNode(head.next.val);
                temp.next = result;
                result = temp;
            } else {
                while(iResult.next != null) {
                    if (iResult.next.val <= head.next.val) {
                        iResult = iResult.next;
                    } else {
                        break;
                    }
                }
                ListNode temp = new ListNode(head.next.val);
                temp.next = iResult.next;
                iResult.next = temp;
            }
            head = head.next;
        }
        return result;
    }

}
