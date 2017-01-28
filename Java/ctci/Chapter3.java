package ctci;
import ctci.MyStack;
import ctci.MyQueue;

public class Chapter3 {
	// Q 3.2
	private class StackNodeWithMin {
		private int data;
		private int min;
		
		public StackNodeWithMin(int data, int min){
			this.data = data;
			this.min = min;
		}
	}

	private class stackMin extends MyStack<StackNodeWithMin>{
		public void push(int data) {
			int newMin = peek().min;
			if (data < newMin) newMin = data;
			super.push(new StackNodeWithMin(data, newMin));
		}
		
		public int min(){
			if (super.isEmpty()) return Integer.MAX_VALUE; 
			return peek().min;
		}
	}
	
	// Q 3.2
	private class QueueViaStack <T> {
		public MyStack<T> newStack = new MyStack();
		public MyStack<T> oldStack = new MyStack();
		
		public void add(T data) {
			newStack.push(data);
		}

		public T remove() {
			if (oldStack.isEmpty()){
				while(newStack.isEmpty()) {
					oldStack.push(newStack.pop());
				}
			}
			return oldStack.pop();
		}
	}
}
