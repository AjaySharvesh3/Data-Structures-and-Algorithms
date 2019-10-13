import java.util.*; 
  
class GFG 
{ 
  
// Representation of node  
static class Node  
{  
    int data;  
    Node next;  
};  
  
// Function to insert node in a linked list  
static Node insert(Node root, int item)  
{  
    Node ptr, temp;  
    temp = new Node();  
    temp.data = item;  
    temp.next = null;  
  
    if (root == null)  
        root = temp;  
    else {  
        ptr = root;  
        while (ptr.next != null)  
            ptr = ptr.next;  
  
        ptr.next = temp;  
    }  
    return root; 
}  
  
// Function which returns new linked list  
static Node newList(Node root1, Node root2)  
{  
    Node ptr1 = root1, ptr2 = root2, ptr;  
    Node root = null, temp;  
  
    while (ptr1 != null) {  
        temp = new Node();  
        temp.next = null;  
  
        // Compare for greater node  
        if (ptr1.data < ptr2.data)  
            temp.data = ptr2.data;  
        else
            temp.data = ptr1.data;  
  
        if (root == null)  
            root = temp;  
        else {  
            ptr = root;  
            while (ptr.next != null)  
                ptr = ptr.next;  
  
            ptr.next = temp;  
        }  
        ptr1 = ptr1.next;  
        ptr2 = ptr2.next;  
    }  
    return root;  
}  
  
static void display(Node root)  
{  
    while (root != null)  
    {  
        System.out.print( root.data + "->");  
        root = root.next;  
    }  
    System.out.println(); 
}  
  
// Driver code  
public static void main(String args[]) 
{  
    Node root1 = null, root2 = null, root = null;  
  
    // First linked list  
    root1=insert(root1, 5);  
    root1=insert(root1, 2);  
    root1=insert(root1, 3);  
    root1=insert(root1, 8);  
  
    System.out.print("First List: ");  
    display(root1);  
  
    // Second linked list  
    root2=insert(root2, 1);  
    root2=insert(root2, 7);  
    root2=insert(root2, 4);  
    root2=insert(root2, 5);  
  
    System.out.print( "Second List: ");  
    display(root2);  
  
    root = newList(root1, root2);  
    System.out.print("New List: ");  
    display(root);  
}  
} 