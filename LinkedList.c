#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void insertAtFront(struct Node** head, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void insertAtRear(struct Node** head, int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;
    newNode->data = data;
    newNode->next = NULL;
    while (last->next!=NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void insertAtPos(struct Node** head, int pos, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *ptr = *head;
    int i = 0;
    while(i!=pos-1){
        ptr = ptr->next;
        i++;
    }
    newNode->data = val;
    newNode->next = ptr->next;
    ptr->next = newNode;
}
// void insertAtPos(struct Node** head, int pos, int value){
//     struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
//     struct Node *p = *head;
//     int i =0;
//     while (i!=pos-1)
//     {
//         p = p->next;
//         i++;
//     }
//     newNode->data = value;
//     newNode->next = p->next;
//     p->next = newNode;
// }

void display(struct Node *ptr){
    while (ptr!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
}
int main()
{
    int select, pos, val;
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;
    do
    {
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Insert Back\n");
        printf("4. Insert at pos\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &val);
            insertAtFront(&head, val);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%d", &val);
            insertAtRear(&head, val);
            break;
        case 4: 
            printf("enter pos number: ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &val);
            insertAtPos(&head, pos, val);
            break;
        default:
            printf("Wrong selection");
            break;
        }
    } while (select != 5);
       
    display(head);
}
