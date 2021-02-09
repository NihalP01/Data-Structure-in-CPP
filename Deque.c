/*Submitted by Nihal Buragohain*/


#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* previous;
	struct node* next;
};


void insertFront(struct node** n, int value)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->previous = NULL;
	newNode->next = *n;
	if(*n != NULL)
		(*n)->previous = newNode;
	*n = newNode;
	return;	
}

void insertEnd(struct node** n, int value)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	struct node* last = *n;
	newNode->data = value;
	newNode->next = NULL;
	if(*n == NULL)
	{
		newNode->previous = NULL;
		*n = newNode;
		return;
	}
	while(last->next != NULL)
		last = last->next;
	last->next = newNode;
	newNode->previous = last;
	return;
}


void deleteFront(struct node** n)
{
	struct node *temp = *n;
	if(*n == NULL)
	{
		printf("The Linked List is empty.");
		return;
	}
	*n = temp->next;
	(*n)->previous = NULL;
	free(temp);
	return;	
}

void deleteEnd(struct node** n)
{
	struct node *last = *n;
	if(*n == NULL)
	{
		printf("The Linked List is empty.\n");
		return;
	}
	while(last->next != NULL)
		last = last->next;
	printf("%d is deleted from the list\n", last->data);	
	(last->previous)->next = NULL;
	free(last);
}

void display(struct node* n)
{
	struct node* last;
	if(n == NULL)
	{
		printf("\n The Linked List is empty.\n");
		return;
	}
	while(n != NULL)
	printf("The Linked list is: ");
	{
		printf("%d ", n->data);
		last = n;
		n = n->next;
	}
	return;
}

int main()
{
	struct node* head = NULL;
	int data, select;
	do
	{
		printf("\n 1. Insert at the front\n 2. Insert at the rear\n 3. Delete from the rear\n 4. Delete from the Front\n 5. Display the Queue\n 6. Exit\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("Enter the value you want to insert: ");
			scanf("%d", &data);
			insertFront(&head, data);
			break;
		case 2: 
			printf("Enter the value you want to insert: ");
			scanf("%d", &data);
			insertEnd(&head, data);
			break;
		case 3:
			deleteEnd(&head);	
			break;
		case 4:
			deleteFront(&head);	
			break;
		case 5:
			display(head);	
			break;
		default:

			break;
		}
	} while (select != 6);
	
}
