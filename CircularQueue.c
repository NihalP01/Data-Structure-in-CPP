/*Submitted by Nihal Buragohain*/

#include<stdio.h>

int elements[5];
int front = -1;
int rear = -1;
void insert(int value){
    if ((front == rear+1) || (front == 0 && rear == 4))
    {
        printf("Can't insert. Queue is full!\n");
    }else
    {
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % 5;
    elements[rear] = value;
    printf("Inserted  %d to the queue\n", value);
  }
}

void delete(){
    int value;
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        value = elements[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }else
        {
            front = (front+1) % 5;
        }
        printf("%d is deleted from th equeue\n", value);
    }
}

void display(){
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
    }else
    {
        printf("The elements of the Queue are: ");
        for ( i = front; i != rear; i = (i+1)% 6)
        {
            printf("%d ",elements[i]);
        }
        printf("%d ", elements[i]);
        printf("\n");
    }
    
    
}

int main(){
    int select, val;
    do
    {
        printf("Select your choice: \n");
        printf("1. Insert elemnets(Max 5)\n");
        printf("2. Delete element\n");
        printf("3. Display the queue\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("Enter the value you want to add: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2: 
            delete();
            break;
        case 3: 
            display();
            break;
        default:
            printf("Invalid Choice!");
            break;
        }
    } while (select!=4);
}