class GFG 
{ 
      
// Structure for a node  
static class Node  
{  
    int data;  
    Node next;  
};  
  
// Function to insert a node at the beginning  
// of a Circular linked list  
static Node push(Node head_ref, int data)  
{  
    Node ptr1 = new Node();  
    Node temp = head_ref;  
    ptr1.data = data;  
    ptr1.next = head_ref;  
  
    // If linked list is not null then  
    // set the next of last node  
    if (head_ref != null)  
    {  
        while (temp.next != head_ref)  
            temp = temp.next;  
        temp.next = ptr1;  
    }  
    else
        ptr1.next = ptr1; // For the first node  
  
    head_ref = ptr1; 
    return head_ref; 
}  
  
// Delete the node if it is prime  
static Node deleteNode(Node head_ref, Node del)  
{  
    Node temp = head_ref;  
  
    // If node to be deleted is head node  
    if (head_ref == del)  
        head_ref = del.next;  
  
    // traverse list till not found  
    // delete node  
    while (temp.next != del) 
    {  
        temp = temp.next;  
    }  
  
    // copy address of node  
    temp.next = del.next;  
    return head_ref;  
}  
  
// Function to check if a number is prime  
static boolean isPrime(int n)  
{  
    // Corner cases  
    if (n <= 1)  
        return false;  
  
    if (n <= 3)  
        return true;  
  
    // This is checked so that we can skip  
    // middle five numbers in below loop  
    if (n % 2 == 0 || n % 3 == 0)  
        return false;  
  
    for (int i = 5; i * i <= n; i = i + 6)  
        if (n % i == 0 || n % (i + 2) == 0)  
            return false;  
  
    return true;  
}  
  
// Function to delete all prime nodes  
// from the singly circular linked list  
static Node deletePrimeNodes(Node head)  
{  
    Node ptr = head;  
  
    Node next;  
  
    // traverse list till the endl  
    // if node is prime then delete it  
    do 
    {  
        // if node is prime  
        if (isPrime(ptr.data))  
            deleteNode(head, ptr);  
  
        // point to next node  
        next = ptr.next;  
        ptr = next;  
  
    }  
    while (ptr != head);  
        return head; 
}  
  
// Function to print nodes in a  
// given singly linked list  
static void printList(Node head)  
{  
    Node temp = head;  
    if (head != null)  
    {  
        do
        {  
            System.out.printf("%d ", temp.data);  
            temp = temp.next;  
        }  
        while (temp != head);  
    }  
}  
  
// Driver code  
public static void main(String args[])  
{  
    // Initialize lists as empty  
    Node head = null;  
  
    // Created linked list will be  
    // 9.11.32.6.13.20  
    head=push(head, 20);  
    head=push(head, 13);  
    head=push(head, 6);  
    head=push(head, 32);  
    head=push(head, 11);  
    head=push(head, 9);  
  
    System.out.println("Given List : ");  
    printList(head);  
  
    System.out.println( "\nList After deleting prime nodes : ");  
    head=deletePrimeNodes(head);  
    printList(head);  
}  
} 