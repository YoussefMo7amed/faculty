package stack_project;

public class stack {
	public int capacity = 5; // public because if you want to change the capacity
	int [] stack  = new int [capacity]; // main stack
	int top =0;
	int [] stack1 = new int [capacity]; // 1st one after the main
	private int top1 =0;
 
	public stack() {
		int i=0;
		for(i =0 ; i <capacity;i++) {
			stack[i]= i+1; // default stack
		}
	}
		public void push(int n) {
				stack[top]=n;
				top++;
		}
		public int pop() {
				int n;
				top--; // top index > stack index by (1)
				n = stack[top];
				
				stack1[top1] = stack[top]; // for first stack * not the main stack *
				top1++;
				
				stack[top]=0;
			return n;
		}
		public int peek() {
			int n;
				n = stack[top-1];
			return n;
		}

		public int getsize() {
			return top;
		}
		public boolean isEmpty() {
			return top==0;
		}
		public void show() {
			if(top==0){
				System.out.println("the stack is empty!");
			}
			for(int i =0; i<top;i++) {
				System.out.print(stack[i]+" ");
			}
		}
		public void sortAscending() {
			// sorted stack
			if(top1==0){
				System.out.println("you have to pop elements firstly!");
			}
			else {
					boolean r = true;
		        	int value;
		        	while(r) {
		        		r= false; // to end the while loop
		        		for (int i=0; i < (top1-1); i++) {
		        			if(stack1[i]>stack1[i+1]) {
		        				value = stack1[i];
		        				stack1[i]=stack1[i+1];
		        				stack1[i+1]=value;
		        				r = true; // to keep the while loop
		        				}
		        									}
		        			}
		        	for(int i =0; i<top1;i++) {
					System.out.print(stack1[i]+" ");
		        			}
		        	System.out.println();
				}
		}
}
