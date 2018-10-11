#include<stdio.h>
#define qsize 3
typedef struct QUEUE
{
	int arr[qsize];
	int f,t,count;
}queue;

void enqueue(queue *q,int x)
{
	if(q->count==qsize-1)
	{
		printf("\nQueue Overflow");
		return;
	}
	q->t=(++(q->t))%qsize;
	q->arr[(q->t)]=x;
	q->count++;
}
int dequeue(queue *q)
{
	if(q->count==0)
	{
		printf("\nQueue Underflow");
		return -1;
	}
	q->count--;
	return q->arr[(q->f)++];

}
void display(queue *q)
{
	int i;
	if(q->count==0)
		{printf("Queue is Empty");
		return;}
	printf("Elements of Queue are:");
	if(q->t>=q->f)
	{
		for(i=q->f;i<=q->t;i++)
		{
			printf("%d\t",q->arr[i]);
		}
	}
	else
	{
		for(i=q->f;i<qsize;i++)
		printf("%d\t",q->arr[i]);
		for(i=0;i<=q->t;i++)
		printf("%d\t",q->arr[i]);
	}
}

void main()
{
	queue q;
	q.f=0;
	q.t=-1;
	q.count=0;
	int choice,element;
	printf("\nEnter 1 to insert element into circular queue\nEnter 2 to Delete an element\nEnter 3 to Display the contents of circular queue\nEnter 0 to Exit");
	scanf("%d",&choice);

	while(choice)
	{
		if(choice==1)
		{
			printf("\nEnter an Element");
			scanf("%d",&element);
			enqueue(&q,element);
			printf("\n%d is added to the queue",element);
		}
		else if(choice==2)
		{
			element = dequeue(&q);
			if(element!=-1)
			printf("\n%d is deleted from queue",element);
		}
		else if(choice==3)
		{
			display(&q);
		}
	  	printf("\nEnter 1 to insert element into queue\nEnter 2 to Delete an element\nEnter 3 to Display the contents of queue\nEnter 0 to Exit");
	    scanf("%d",&choice);
		}
}
