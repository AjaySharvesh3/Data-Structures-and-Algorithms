# Linked List in Java

Hello World!

Linked list is pretty simple in case of Java, when compared to C++ or other languages.

### Creating a list
In java we could create a linked list by importing *LinkedList* package from *util*. To create a linked list, just create an oblect for the class *LinkedList*. The syntax for creating Linked List object is,

```Java
LinkedList<type> object = new LinkedList<type>();
```

### Linked List functions

Some of Linked **List functions** supported in Java are:

| Function	| Usage	|
| --------------| :----:|
| add(index, element)| Used to insert the element in specified location.|
| addFirst(element)| Used to insert element at the front (beginning) of list.|
| addLast(element)| Used to insert element at the last (end) of the list.|
| size()| Used to return the number of elements in the list.|
| add(element)| Used to append the element to the end of a list.|
| contains(element)| Used to return true if the list contains a specified element.|
| remove(element)| Used to remove the first occurence of the specified element in the list.|
| getFirst()| Returns the first element in a list.|
| getLast() | Returns the last element in a list.|
| indexOf(element)| Returns the index in a list of the first occurrence of the specified element, or -1 if the list does not contain any element.|
| lastIndexOf(element)| Returns the last element's index.|

## Code

Let us see a simple program, that creates a linked list, gets value from user and inserts to the linked list and finally displays the elements of the list.

```java
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
```

**Output:**

![output](https://raw.githubusercontent.com/sriram23/Data-Structures-and-Algorithms./d13d2c47a2fc5236d2193cdead2a8f1b14d77e1c/Algorithm_Solutions/Image/Screenshot%20from%202018-10-06%2022-24-46.png)
