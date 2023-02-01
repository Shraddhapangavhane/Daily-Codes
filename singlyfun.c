#include<stdio.h>
#include<stdlib.h>

typedef struct employee{
	int data;
	struct employee *next;
}emp;

	emp* head=NULL;
		
emp * createnode()
{
	emp * newnode=(emp*)malloc(sizeof(emp));
	
	printf("Enter a data\n");
	scanf("%d",&newnode->data);
	
	newnode->next=NULL;
	
	return newnode;
}

void addnode()
{
	emp* newnode=createnode();
	
	
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		emp* temp=head;
		
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void printll()
{
	emp* temp=head;
	
	while(temp!=NULL)
	{
		printf("%d||",temp->data);
		
		temp=temp->next;
		
	 } 
}
void addFirst()
{
	emp* newnode=createnode();
	
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void addatpos(int pos)
{
	emp* newnode=createnode();
	
	emp* temp=head;
	
	while(pos-2)
	{
		temp=temp->next;
		pos--;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void deleteFirst()
{
	emp *temp=head;
	
	head=temp->next;
	free(temp);
	
}
void deleteLast()
{
	emp *temp=head;
	
	while(temp->next->next !=NULL)
	{
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
	
}
void main()
{
char choice;
	
	do{
		printf("1.addnode\n");
		printf("2.addFirst\n");
		printf("3.addatPos\n");
		printf("4.printll\n");
		printf("5.DeleteFirst\n");
		printf("6.DeleteLast");
		
		int ch;
		
		printf("\nEnter your choice:\n");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				addnode();
				break;
			case 2:
				addFirst();
				break;
			case 3:
				{				
				int pos;
				printf("Enter pos\n");
				scanf("%d",&pos);
				addatpos(pos);
				}
				break;
				
			case 4:
				printll();
				break;
			
			case 5:
				deleteFirst();
				break;
				
			case 6:
				deleteLast();
				break;
				
			default:
				printf("Wrong choice\n");
		}
		
	getchar();
		printf("Do you want to continue:\n");
		scanf("%c",&choice);
		
	}while(choice=='y'||choice=='Y');
}
