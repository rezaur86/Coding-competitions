package leetcode;

import java.util.*;

// https://leetcode.com/problems/merge-k-sorted-lists/

public class mergeKList {
	private class ListNode {
		int val;
		ListNode next;
		ListNode(int x) { val = x; }
	}
	
    private class QueueNode {
        ListNode list;
        int size;
        public QueueNode(ListNode l, int s) {
            list = l;
            size = s;
        }
    }
    
    private class ListComparator implements Comparator<QueueNode> {
        public int compare(QueueNode n1, QueueNode n2) {
            return n1.size = n2.size;
        }
    }
    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;
        if (n == 0) return null;
        if (n == 1) return lists[0];
        PriorityQueue<QueueNode> queue = new PriorityQueue<QueueNode>(new ListComparator());
        for (int i = 0; i < n; i++) {
            ListNode iList = lists[i];
            int iSize = 0;
            while(iList != null) {
                iSize++;
                iList = iList.next;
            }
            queue.add(new QueueNode(lists[i], iSize));
        }
        
        while (queue.size() > 1) {
            QueueNode qN1 = queue.poll();
            QueueNode qN2 = queue.poll();
            queue.add(new QueueNode(merge(qN1.list, qN2.list), qN1.size + qN2.size));
        }
        return queue.poll().list;
    }
    
    public ListNode mergeKListsWithQueue(ListNode[] lists) {
        int n = lists.length;
        if (n == 0) return null;
        if (n == 1) return lists[0];
		Queue<ListNode> queue = new LinkedList<ListNode>();

        for (int i = 0; i < n; i++) {
            if (lists[i] != null)
                queue.add(lists[i]);
        }
        
        while (queue.size() > 1) {
            ListNode n1 = queue.poll();
            ListNode n2 = queue.poll();
            queue.add(merge(n1, n2));
        }
        return queue.poll();
    }
    
    public ListNode merge(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val <= l2.val) {
            l1.next = merge(l1.next, l2);
            return l1;
        }
        else {
            l2.next = merge(l1, l2.next);
            return l2;
        }
    }
}
