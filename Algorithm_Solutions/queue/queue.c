#include<stdio.h>
#include<stdlib.h>
#define qsize 100
typedef struct QUEUE
{
	int arr[qsize];
	int f,t;
}queue;

void enqueue(queue *q,int x)
{
	if(q->t+1==qsize)
	{
		printf("\nQueue Overflow");
		return;
	}
	q->arr[++(q->t)]=x;
}
int dequeue(queue *q)
{
	if(q->t<q->f)
	{
		printf("\nQueue Underflow");
		exit(1);
	}
	return q->arr[(q->f)++];

}
void display(queue *q)
{
	int i;
	if(q->t<q->f)
		{printf("Queue is Empty");
		return;}
	printf("Elements of Queue are:");
	for(i=q->f;i<=q->t;i++)
	{
		printf("%d\t",q->arr[i]);
	}

}
int isEmpty(queue *q)
{
	if(q->t<q->f)
		{
			return 1;
		}
	return 0;
}

void main()
{
	queue q;
	q.f=0;
	q.t=-1;
	int choice,element;
	printf("\nEnter 1 to insert element into queue\nEnter 2 to Delete an element\nEnter 3 to Display the contents of queue\nEnter 0 to Exit");
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
