#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node* next;
}typedef node;

node* start = NULL;

void push()
{
	int num;
	printf("Enter a Number: ");
	scanf("%d",&num);
	node* temp = (node*)malloc(sizeof(node));
	temp->value = num;
	temp->next = start;
	start = temp;
}
void pop()
{
	if(start==NULL)
	{
		printf("Stack Underflow!\n");
	}
	else{
		node* temp = start->next;
		int value = start->value;
		printf("%d is deleted from stack\n",value);
		free(start);
		start = temp;
	}
}

void display()
{
	node* temp;
	temp = start;
	while(temp!=NULL)
	{
		printf("%d   ",temp->value);
		temp=temp->next;
	}
}

int main()
{
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
		}
	}
}
