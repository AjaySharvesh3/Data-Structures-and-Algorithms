class LinkedList(object): 
    def __init__(self): 
    # head of list 
        self.head = None
  
    # Linked list Node 
    class Node(object): 
        def __init__(self, d): 
            self.data = d 
            self.next = None
  
    # Inserts a new Node at front of the list. 
    def push(self, new_data): 
  
        # 1 & 2: Allocate the Node & 
        # Put in the data 
        new_node = self.Node(new_data) 
  
        # 3. Make next of new Node as head 
        new_node.next = self.head 
  
        # 4. Move the head to point to new Node 
        self.head = new_node 
  
    # Main function that inserts nodes of linked list q into p at 
    # alternate positions. Since head of first list never changes 
    # and head of second list/ may change, we need single pointer 
    # for first list and double pointer for second list. 
    def merge(self, q): 
        p_curr = self.head 
        q_curr = q.head 
  
        # While there are available positions in p; 
        while p_curr != None and q_curr != None: 
  
            # Save next pointers 
            p_next = p_curr.next
            q_next = q_curr.next
  
            # make q_curr as next of p_curr 
            q_curr.next = p_next # change next pointer of q_curr 
            p_curr.next = q_curr # change next pointer of p_curr 
  
            # update current pointers for next iteration 
            p_curr = p_next 
            q_curr = q_next 
        q.head = q_curr 
  
    # Function to print linked list 
    def printList(self): 
        temp = self.head 
        while temp != None: 
            print str(temp.data), 
            temp = temp.next
        print '' 
  
# Driver program to test above functions 
llist1 = LinkedList() 
llist2 = LinkedList() 
llist1.push(3) 
llist1.push(2) 
llist1.push(1) 
  
print "First Linked List:"
llist1.printList() 
  
llist2.push(8) 
llist2.push(7) 
llist2.push(6) 
llist2.push(5) 
llist2.push(4) 
  
print "Second Linked List:"
  
llist2.printList() 
llist1.merge(llist2) 
  
print "Modified first linked list:"
llist1.printList() 
  
print "Modified second linked list:"
llist2.printList() 
  
