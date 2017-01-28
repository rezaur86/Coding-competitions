/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
package leetcode;

//https://leetcode.com/problems/sort-list/

public class SortLinkedList {
    public ListNode sortList(ListNode head) {
        if (head == null) return head;
        if (head.next == null) return head;
        ListNode pre = head;
        ListNode p1 = head;
        ListNode p2 = head;
        while (p2 != null && p2.next != null) {
            pre = p1;
            p1 = p1.next;
            p2 = p2.next.next;
        }
        
        pre.next = null; // two make two sperate list
        
        ListNode sL = sortList(head);
        ListNode sR = sortList(p1);
        
        return mergeList(sL, sR);
    }
    
    public ListNode mergeList(ListNode sL, ListNode sR) {
        if (sL == null) return sR;
        if (sR == null) return sL;
        if (sL.val > sR.val) {
            sR.next = mergeList(sL, sR.next);
            return sR;
        }
        else {
            sL.next = mergeList(sL.next, sR);
            return sL;
        }
   }
}