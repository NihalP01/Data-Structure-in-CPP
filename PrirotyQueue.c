/*Submitted by Nihal Buragohain*/


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int priority;
	int data;
	struct node *next;
}Node;

Node *front = NULL;

void Insert(int data, int  priority)
{
	Node *temp, *q;
	
	temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->priority = priority;
	if(front == NULL || priority < front->priority)
	{
		temp->next = front;
		front = temp;
	}
	else
	{
		q = front;
		while(q->next != NULL && q->next->priority <= priority)
			q = q->next;
		temp->next = q->next;
		q->next = temp;
	}
}


void Delete()
{
	Node *temp;
	if(front == NULL)
		printf("Queue is empty\n");
	else
	{
		temp = front;
		printf("Deleted value is: %d with priority: %d\n",temp->data, temp->priority);
		front = front->next;
		free(temp);
	}
}

void Display()
{
	Node *ptr;
	ptr = front;
	if(front == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		while(ptr != NULL)
		{
			printf("Priority: %d, Value: %d\n",ptr->priority,ptr->data);
			ptr = ptr->next;
		}
	}

}


int main()
{

	int select;
	int data;
	int priority;
	
	do
	{
		printf("Select your choice: \n");
		printf("1. Insert an element\n");
		printf("2. Delete an element\n");
		printf("3. Diplay the Queue\n");
		printf("4. Exit\n");
		scanf("%d",&select);
		
		
		switch(select)
		{
			case 1:
				printf("Enter the value to insert: ");
				  	scanf("%d",&data);
				printf("Enter the priority of %d: ", data);
					scanf("%d",&priority);
				  	Insert(data, priority);
				  	break;
			
			case 2:
				printf("Deleting the element with higher priority\n");
				Delete();
				  	break;
				  	
			case 3:
				Display();
					break; 		
			case 4:
				break;
				
			default:
				printf("Invalid Option\n");
				break;
				  	
		}
	}
	while(select != 4);

}

























