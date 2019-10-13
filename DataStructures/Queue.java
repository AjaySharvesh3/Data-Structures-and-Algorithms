package queue;

public class Queue {
	
	int capacity,size,front ,rear;
	int array[];
	
	Queue(int capacity){
		this.capacity=capacity;
		this.size=0;
		front =0;
		rear=capacity-1;
		array = new int[capacity-1];
	
	}
	
	boolean isFull(Queue q) {
		return(q.size==q.capacity);
	}
	
	boolean isEmpty(Queue q) {
		return(q.size==0);
	}
	
    void enque(int item) {
    	
    	if(isFull(this))
    	return;
    	
    	this.rear=(this.rear+1)%this.capacity;
    	this.array[this.rear]=item;
    	this.size+=1;
		System.out.println(item+" enqued");
	}
	
    int deque() {
    	if(isEmpty(this))
        return Integer.MIN_VALUE;
    	
    	int item=this.array[front];
    	this.front=(this.front+1)%this.capacity;
    	this.size-=1;
    	System.out.println(item +" dequed");
    	return item;
    	
    	
    }
	public static void main(String args[]) {
		
		Queue q=new Queue(5);
		q.enque(1);
		q.enque(2);
		q.deque();
		q.deque();
		q.isEmpty(q);
		
	
	}
}
