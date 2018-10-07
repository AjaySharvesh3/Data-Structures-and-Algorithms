//This program tells you how to create a linkedlist, add values and display values in Java.
import java.util.LinkedList;
import java.util.Scanner;

public class LinkedClass {
	public static void main(String args[]) {
		LinkedList<String> Name = new LinkedList<String>();
		Scanner in = new Scanner(System.in);
		String nameTemp;
		int flag = 1;
		while(flag == 1) {
			System.out.println("Enter value to be inserted:");
			nameTemp = in.next();
			Name.add(nameTemp);
			System.out.println("Value inserted successfully. Would you like to add some more? 1|0");
			flag = in.nextInt();
		}
		System.out.println("The following are the records in the linked list:");
		System.out.println(Name.toString());
	}
}
