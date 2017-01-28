package ctci;
import java.util.*;

public class chapter2 {
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

		public Node deleteNode(int d){
			Node head = this;
			if (head.data == d) {
				head = head.next;
				return head;
			}
			while (head.next != null){
				if (head.next.data == d){
					head.next = head.next.next;
					return this;
				}
				head = head.next;
			}
			return this;
		}
		
		public Node reverseList(){
			Node head = null;
			Node old_list = this;
			while(old_list != null){
				Node temp = head;
				head = new Node(old_list.data);
				head.next = temp;
				old_list = old_list.next;
			}
			return head;
		}

		public void printList(){
			Node head = this;
			System.out.print("" + head.data);
			while (head.next != null){
				System.out.print("->" + head.next.data);
				head = head.next;
			}
			System.out.print("\n");
		}
	}
	int RAND_BOUND = 10;

	public Node buildRandomList(int size){
		Random rand = new Random(System.currentTimeMillis());
		Node head = new Node(rand.nextInt(RAND_BOUND));
		for (int i = 1; i < size; i++){
			head.appendToTail(rand.nextInt(RAND_BOUND));
		}
		return head;
	}
	
	public Node buildSequentialList(int size){
		int seq = 0;
		Node head = new Node(0);
		for (int i = 1; i < size; i++){
			head.appendToTail(++seq);
		}
		return head;
	}
	
	public Node buildCharList(char[] chars){
		Node head = new Node(chars[0]);
		for (int i = 1; i < chars.length; i++){
			head.appendToTail(chars[i]);
		}
		return head;
	}
	
	public Node joinList(Node list1, Node list2){
		Node joinedList = list1;
		while(list1.next != null){
			list1 = list1.next;
		}
		list1.next = list2;
		return joinedList;
	}
	
	// Q 2.1
	public Node removeDups(Node head){
		Node unique = head;
		Node dup;
		while (unique.next != null){
			dup = unique;		
			while (dup.next != null){
				if (unique.data == dup.next.data){
					dup.next = dup.next.next;
				}
				else dup = dup.next;
			}
			if (unique.next != null)
				unique = unique.next;
		}
		return head;
	}

	// Q 2.2
	public Node kthToLast(Node head, int k){
		Node k_last = head;
		Node end = k_last;
		for (int i = 0; i < k; i++){
			if (end.next != null){
				end = end.next;
			}
			else return null;
		}
		while (end != null){
			end = end.next;
			k_last = k_last.next;
		}
		return k_last;
	}
	
	// Q 2.4
	public Node partition(Node head, int x){
		Node smaller = head;		
		while (head.next != null){
			if (head.next.data < x){
				Node temp = head.next;
				head.next = temp.next;
				temp.next = smaller;
				smaller = temp;
			}
			else head = head.next;
			if (head == null) break;
		}
		return smaller;
	}
	
	// Q 2.5
	public Node sumList(Node num1, Node num2){
		if (num1 == null) return  num2; 
		if (num2 == null) return  num1;
		Node result = new Node(0); // carries the carry over
		Node result_head = result;
		while (num1 != null || num2 != null){
			int n1;
			int n2;
			if (num1 == null) n1 = 0;
			else {
				n1 = num1.data;
				num1 = num1.next;
			}
			if (num2 == null) n2 = 0; 
			else {
				n2 = num2.data;
				num2 = num2.next;
			}
			int carryover = (result.data + n1 + n2) / 10;
			result.data = (result.data + n1 + n2) % 10;
			if (num1 != null || num2 != null || carryover>0)
				result.next = new Node(carryover);
			result = result.next;
		}
		return result_head;
	}

	private Node sumListReverseHidden(Node num1, Node num2){
		if (num1.next == null && num2.next == null){
			Node result = new Node((num1.data + num2.data) / 10);
			result.next = new Node((num1.data + num2.data) % 10);
			return result;
		}
		if (num1.next == null){
			return sumListReverseHidden(num1, num2.next);
		}
		if (num2.next == null){
			return sumListReverseHidden(num1.next, num2);
		}
		Node carried_result = sumListReverseHidden(num1.next, num2.next);
		int carry_over = carried_result.data;
		carried_result.data = (carry_over + num1.data + num2.data) % 10;
		Node result = new Node((carry_over + num1.data + num2.data) / 10);
		result.next = carried_result;
		return result;
	}

	public Node sumListReverse(Node num1, Node num2){
		Node result = sumListReverseHidden(num1, num2);
		if (result.data == 0) return result.next;
		else return result;
	}

	// Q 2.6
	public Boolean isPalindrome(Node head){
		Node fast;
		if (head.next != null) {
			fast = head.next;
		}
		else {
			return true;
		}
		Stack<Integer> seenEl = new Stack<Integer>();
		seenEl.push(head.data);
		while(fast.next != null){
			fast = fast.next;
			head = head.next;
			if (fast.next != null) {
				fast = fast.next;
				seenEl.push(head.data);
			}
		}
		while(head.next != null){
			if (head.next.data != seenEl.pop()) {
				return false;
			}
			head = head.next;
		}
		return true;
	}
	
	//Q 2.7
	public Boolean isIntersect(Node list1 , Node list2){
		Node savedList2 = list2;
		while(list1 != null){
			list2 = savedList2;
			while(list2 != null){
				if (list1 == list2){
					return true;
				}
				list2 = list2.next;
			}
			list1 = list1.next;
		}
		return false;
	}
	
	public static void main(String[] args){
		chapter2 ch2 = new chapter2();
		Node seq_list = ch2.buildSequentialList(15);
		seq_list.printList();
/*		// Testing the base methods
		Node deletedHead = seq_list.deleteNode(0);
		deletedHead.deleteNode(14);
		deletedHead.deleteNode(5);
		deletedHead.printList();
*/
		Node rand_list = ch2.buildRandomList(15);
		System.out.print("Q 2.1 Input ");
		rand_list.printList();
		System.out.print("Q 2.1 Output ");
		ch2.removeDups(rand_list).printList();

		System.out.print("Q 2.2 Input ");
		seq_list.printList();
		System.out.print("Q 2.2 Output ");
		ch2.kthToLast(seq_list, 5).printList();

		System.out.print("Q 2.4 Input ");
		Node rand_list24 = ch2.buildRandomList(15);
		rand_list24.printList();
		System.out.print("Q 2.4 Output ");
		rand_list24 = ch2.partition(rand_list24, 5);
		rand_list24.printList();

		System.out.println("Q 2.5 Input ");
		Node rand_list25_1 = ch2.buildRandomList(5);
		Node rand_list25_2 = ch2.buildRandomList(5);
		rand_list25_1.printList();
		rand_list25_2.printList();
		System.out.print("Q 2.5 Output ");
		ch2.sumList(rand_list25_1, rand_list25_2).printList();
		System.out.print("Q 2.5 Output reverse list ");
		ch2.sumListReverse(rand_list25_1, rand_list25_2).printList();

		System.out.print("Q 2.6 Input ");
		char[] chars = {'a', 'b', 'c', 'd', 'c', 'b', 'a'};
		Node rand_list26 = ch2.buildCharList(chars);
		rand_list26.printList();
		System.out.println("Q 2.6 Output " + ch2.isPalindrome(rand_list26));

		System.out.print("Q 2.7 Input ");
		Node rand_list27_1 = ch2.buildRandomList(5);
		Node rand_list27_2 = ch2.buildSequentialList(5);
		Node rand_list27_3 = ch2.buildSequentialList(5);
		Node joined_list_1 = ch2.joinList(rand_list27_1, rand_list27_2);
		Node joined_list_2 = ch2.joinList(rand_list27_3, rand_list27_2);
		joined_list_1.printList();
		joined_list_2.printList();
		System.out.println("Q 2.6 Output " + ch2.isIntersect(joined_list_1, joined_list_2));
}
}
