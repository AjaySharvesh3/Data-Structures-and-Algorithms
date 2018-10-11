#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}NODE;
NODE *head;

void push(int x)
{
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	p->info=x;
	p->next=head;
	head=p;

}

int pop()
{
	if(head==NULL)
	{
		printf("\nSTACK UNDERFLOW");
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
		printf("\n1-Push an element\n2-Pop an element\n3-Print elements of stack\n-1 Exit\n");
		scanf("%d",&choice);
		if(choice==-1)
			break;
		else if(choice==1)
		{
			printf("\nEnter element to push:");
			scanf("%d",&n);
			push(n);
		}
		else if(choice==2)
		{
			printf("\nPopped element is %d",pop());
		}
		else if(choice==3)
		{
			printll();
		}
	}
	
	return 0;
}
















