package stack_project;
import java.io.*;
import java.util.*;

public class LoadeStack {
	private Scanner file;
	
	public void openFile() {
		try {
			file = new Scanner (new File ("stackfile.txt"));
		}
		catch(Exception e) {
			System.out.println("√Õ« ÂÊ ›Ì‰ø");
		}
	}
	
	public void readFile() {
		while(file.hasNext()) {
			int a = file.nextInt();
			System.out.println((a+100));
		}
	}
	public void closeFile() {
		file.close();
	}
	
}
