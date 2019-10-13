import math 
  
# class for a Sum 
class Sum: 
    tsum = None
  
# A Linked list node  
class Node: 
    def __init__(self,data): 
        self.data = data 
        self.next = None
  
# function to insert a node at the  
# beginning of the linked list  
def push(head, data): 
    if not head: 
        return Node(data) 
  
    # put in the data  
    # and allocate node  
    new_node = Node(data) 
  
    # link the old list to the new node  
    new_node.next = head 
  
    # move the head to point 
    # to the new node  
    head = new_node 
    return head 
  

def sumOfNode(head, S): 
      
    # if head = NULL 
    if not head: 
        return
      
    # recursively traverse the  
    # remaining nodes 
    sumOfNode(head.next, S) 
      
    # accumulate sum 
    S.tsum += head.data  
  
# utility function to find  
# the sum of nodes 
def sumOfNodesUtil(head): 
    S = Sum() 
    S.tsum = 0
      
    # find the sum of nodes 
    sumOfNode(head, S) 
      
    # required sum 
    return S.tsum 
  
# Driver Code 
if __name__=='__main__': 
    head = None
  
    # create linked list 7->6->8->4->1  
    head = push(head, 7) 
    head = push(head, 6) 
    head = push(head, 8) 
    head = push(head, 4) 
    head = push(head, 1) 
    print("Sum of Nodes = {}" .  
           format(sumOfNodesUtil(head))) 
