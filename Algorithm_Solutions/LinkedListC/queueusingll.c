#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}NODE;
NODE *head;
void enqueue(int x)
{
	NODE *p=head,*q;
	q=(NODE *)malloc(sizeof(NODE));
	q->info=x;
	q->next=NULL;
	if(head==NULL)
	{
		head=q;
		return;
	}
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	
}
int dequeue()
{
	if(head==NULL)
	{
		printf("\nQUEUE UNDERFLOW");
		exit(1);
	}
	int x=head->info;
	head=head->next;
	return x;
}

void printll()
{
	NODE *p=head;
	printf("\n");
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p=p->next;
	}
}

int main()
{
	int choice,n;
	while(1)
	{
		printf("\n1-Enqueue an element\n2-Dequeue an element\n3-Print elements of queue\n-1 Exit\n");
		scanf("%d",&choice);
		if(choice==-1)
			break;
		else if(choice==1)
		{
			printf("\nEnter element to enqueue:");
			scanf("%d",&n);
			enqueue(n);
		}
		else if(choice==2)
		{
			printf("\nDequeued element is %d",dequeue());
		}
		else if(choice==3)
		{
			printll();
		}
	}

	return 0;
}
