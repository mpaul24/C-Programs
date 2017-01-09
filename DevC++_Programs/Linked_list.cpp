#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;//C++ : node* link
}typedef node;

	node* start = NULL;//head node
	
	//Creation
	void create()
	{
		int choice=0;
		do{
			int num;
			scanf("%d",&num);
			node* temp = (node*) malloc (sizeof(node));
			temp->data = num;
			temp->link = NULL;
			if(start==NULL)
			{
				start = temp;
			}
			else
			{
				node* temp1;
				temp1 = start;
				node* prev;
				while(temp1!=NULL)
				{
					prev = temp1;//to get the track of the last node
					temp1 = temp1->link;//can lead to null,so 'prev' is introduced
				}
				prev->link = temp;//adding a node at the end of the linked list
			}
			//asking if want to enter a number
			scanf("%d",&choice);
		}while(choice);
	}
	
	//Display
	void display()
	{
		node* temp;
		temp = start;
		while(temp!=NULL)
		{
			printf("%d   ",temp->data);
			temp = temp->link;
		}
	}
	
	//Insert at the Beginning
	void insertBeginning()
	{
		int num;
		scanf("%d",&num);
		node* temp = (node*) malloc (sizeof(node));
		temp->data = num;
		temp->link = start;
		start = temp;
	}
	
	//Insert after a number in the Linked List
	void insert()
	{
		int num;
		int got = 1;
		scanf("%d",&num);
		node* prev;//contain the node that contain the value = num
		node* next = start->link;//next node
		prev = start;
		while(prev->data!=num && next!=NULL)
		{
			//Searching for the number
			prev = prev->link;
			next = next->link;
			if(next==NULL)
			{
				got = 0;
			}
		}
		if(got==0)
		{
			printf("TRY AGAIN!!");
		}
		else
		{
			int num1; scanf("%d",&num1);
			node* temp = (node*)malloc(sizeof(node));
			temp->data = num1;
			prev->link = temp;
			temp->link = next;
			
		}
		
		
	}
	
	void insertBefore()
	{
		int num;
		int got = 1;
		scanf("%d",&num);
		node* next;//node that contain te value = num
		node* prev = NULL;// previous node
		next = start;
		while(next->data!=num && next!=NULL)
		{
			prev = next;
			next = next->link;
			if(next==NULL)
			{
				got = 0;
			}
		}
		if(got==0)
		{
			printf("TRY AGAIN!!");
		}
		else
		{
			int num1; scanf("%d",&num1);
			node* temp = (node*)malloc(sizeof(node));
			temp->data = num1;
			prev->link = temp;
			temp->link = next;
			
		}
	}
	
	void deleteFunc()
	{
		int num;
		int got = 1;
		scanf("%d",&num);
		node* temp = start;//node that contain te value = num
		node* prev = NULL;// previous node
		node* next = start->link;
		while(temp->data!=num && temp!=NULL)
		{
			prev = temp;
			temp = next;//if it is NULL,Number not found
			next = next->link;//if last node the it is NULL
			if(temp==NULL)
			{
				got = 0;
			}
		}
		if(got==0)
		{
			printf("TRY AGAIN!!");
		}
		else{
				if(prev!=NULL){
					prev->link = next;
					free(temp);
				}
				else
				{
					start = next;
					free(temp);
				}
				
			}	
		}
		
	void reverse()
	{
		node* temp;//conatin the current node
		node* prev = NULL;//contain the previous node...initially NULL
		node* next;//conatin the next node i.e temp->next
		temp = start;
		while(temp!=NULL)
		{
			next = temp->link;
			temp->link = prev;
			prev = temp;//setting the current node as prev
			temp = next;//checking for the next node
		}
		start = prev;//setting the last node as start
	} 
	

int main()
{
	int choice;
	while(1)
	{
		printf("\n1.Create\n2.Display\n3.Insert Beginnning\n4.Insert After n\n5.Insert Before n\n6.Delete\n7.Reverse\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				insertBeginning();
				break;
			case 4:
				insert();
				break;
			case 5:
				insertBefore();
				break;
			case 6:
				deleteFunc();
				break;
			case 7:
				reverse();
				break;
				
				
		}
	}	
}


