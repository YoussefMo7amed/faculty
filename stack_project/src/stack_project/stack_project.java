package stack_project;
import java.util.*;

public class stack_project {
    public static void intro() { // a guidance to the user
        System.out.println("Please Enter:");
        System.out.println(" *(push) to add an element to the stack.");
        System.out.println(" *(peek) to return the value of the element on the top of the stack.");
        System.out.println(" *(pop) removes and returns the element on the top of the stack.");
        System.out.println(" *(size) to get the number of elements in the stack.");
        System.out.println(" *(empty) to know if the stack empty or not.");
        System.out.println(" *(show) to show the current stack.");
        System.out.println(" *(sort) to sort the stack.");
        System.out.println(" *(stop) to stop.");
        System.out.println("Enter an operation!");
    }
    public static void op(String input) {
    	Scanner in = new Scanner(System.in);
    	stack s = new stack(); // the main stack
    	int n;
    	String word = input; // to get the input value and 
    	while(!word.contains("stop")) // to get the end of the program
    		{
    		String ss;
    		if(word.equals("push")) {
    			// if the stack is full 
    			if(s.top==s.capacity) {
    				System.out.println("the stuck is overload!");
    				System.out.println("please enter (pop) to remove last element or");    						
    			}
    			else {
		           			System.out.println("Enter a number ");
				        		try {
				        			n=in.nextInt();
				        			s.push(n);
				        			
				        		}
				        		catch (Exception e)  {
				        			System.out.println("Please enter a number correctly");
				        		}
    			}
        	}
    		
    		// peek 
    		else if(word.equals("peek")) {
            	try {
            		System.out.println(s.peek());
        		}
        		catch (Exception e)  {
        			System.out.println("the stack is empty!");
        		}
    		}
    		// pop
        	else if(word.equals("pop")) {
        			if(s.top==0) { // if the stack is empty
        				System.out.println("the stuck is empty");
        				System.out.println("please enter (push) to add an element or");
        			}
        			else
        			System.out.println(s.pop());
        	}
    		// size of the main stack
        	else if(word.equals("size")) {
            	System.out.println(s.getsize());

        	}
    		// is the stack empty or not
        	else if(word.equals("empty")) {
            			if(s.isEmpty()) {
            				System.out.println("Yes");  // instead of true
            			}
            			else if(!s.isEmpty()) {
            				System.out.println("No"); // instead of false
            			}

        	}
    		// sorting the stack that takes "the poped elements"
    		// from the main stack
        	else if(word.equals("sort")) {
            	s.sortAscending();

        	}
    		// show the main stack elements by the entrance priority 
        	else if(word.equals("show")) {
        		s.show();
        		System.out.println();
        	}
    		// if the operation enter un-correctly
        	else {
        		System.out.println("Enter the operation correctly");
        		}
    		System.out.println("-------------------------");
    		System.out.println("enter an operation!");	
    		System.out.println("-------------------------");

    		// take the new input
        	 ss =in.next();
        	// to keep the loop working
        	 word = ss.toLowerCase();
    	}
    	// if the user entered "stop" to stop the program
    	System.out.println("Thank you!");
    }
    
    public static void main(String[] args) {
    	intro(); // just a guide to the user 
    	Scanner in = new Scanner(System.in);
    	String input = in.next(); // user input
    	input.trim(); // if there are spaces
    	op(input.toLowerCase()); // to lower to be compared with if conditions
    }
    
}
