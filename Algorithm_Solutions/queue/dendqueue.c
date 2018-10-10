#include<stdio.h>
#define qsize 100
typedef struct QUEUE
{
	int arr[qsize];
	int f,t,count;
}queue;

void enqueuelast(queue *q,int x)
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
void enqueuestart(queue *q,int x)
{
	if(q->count==qsize-1)
	{
		printf("\nQueue Overflow");
		return;
	}
	q->count++;
	if(q->f==0)
	{
		q->f=qsize-1;
		q->arr[(q->f)]=x;
		return;
	}
	q->arr[--(q->f)]=x;
}
int dequeuestart(queue *q)
{
	if(q->count==0)
	{
		printf("\nQueue Underflow");
		return -1;
	}
	q->count--;
	if(q->f==qsize-1)
	{
		q->f==0;
		return q->arr[qsize-1];
	}
	return q->arr[(q->f)++];

}
int dequeuelast(queue *q)
{
	if(q->count==0)
	{
		printf("\nQueue Underflow");
		return -1;
	}
	q->count--;
	if(q->t==0)
	{
		q->t==qsize-1;
		return q->arr[0];
	}
	return q->arr[(q->t)--];
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
	int choice,element,c2;
	printf("\nEnter 1 to insert element into queue\nEnter 2 to Delete an element\nEnter 3 to Display the contents of queue\nEnter 0 to Exit");
	scanf("%d",&choice);

	while(choice)
	{
		if(choice==1)
		{
			printf("\nEnter 1 to insert at start\tEnter 2 to insert at last:");
			scanf("%d",&c2);
			printf("\nEnter an Element");
			scanf("%d",&element);
			if(c2==1)
			{enqueuestart(&q,element);
			printf("\n%d is added to the queue at start",element);
			}
			else if(c2==2)
			{enqueuelast(&q,element);
			printf("\n%d is added to the queue at last",element);}
		}
		else if(choice==2)
		{
			printf("\nEnter 1 to delete at start\tEnter 2 to delete at last:");
			scanf("%d",&c2);
			if(c2==1)
			{element=dequeuestart(&q);
			printf("\n%d is deleted from the queue at start",element);
			}
			else if(c2==2)
			{element=dequeuelast(&q);
			printf("\n%d is deleted from the queue at last",element);}
		}
		else if(choice==3)
		{
			display(&q);
		}
	  	printf("\nEnter 1 to insert element into queue\nEnter 2 to Delete an element\nEnter 3 to Display the contents of queue\nEnter 0 to Exit");
	    scanf("%d",&choice);

	  }
}
