/* Submitted by Nihal Buragohain , CSE-27/19 */

#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *left, *right;
};

struct node* createNode(int newData)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct node* insert(struct node* n, int newData) 
{ 
    if(n == NULL) 
        return createNode(newData); 
	if(newData < n->data) 
        n->left = insert(n->left, newData); 
    else if (newData > n->data) 
        n->right = insert(n->right, newData); 
  	return n; 
}

void inorder(struct node* n)
{
	if(n != NULL)
	{
		inorder(n->left);
		printf("%d ", n->data);
		inorder(n->right);
	}
}

void preOrder(struct node* n)
{
	if(n != NULL)
	{
		printf("%d ", n->data);
		preOrder(n->left);
		preOrder(n->right);
	}
}

void postOrder(struct node* n)
{
	if(n != NULL)
	{
		postOrder(n->left);
		postOrder(n->right);
		printf("%d ", n->data);
	}
}

int main()
{
	int select, input, inputArr[15];
	struct node* root = NULL;
	do
    {
        printf("\n1. Insert a value to the Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Pre Order Traversal\n");
        printf("4. Post Order Traversal\n");
        printf("5. Exit\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            if (root == NULL)
            {
                printf("Enter the root Node: ");
                scanf("%d", &input);
                root = createNode(input);
            }else
            {
                printf("Enter the value to add in the Tree: ");
                scanf("%d", &input);
                insert(root, input);
            }
            break;
        case 2: 
            inorder(root);
            break;
        case 3: 
            preOrder(root);
            break;
        case 4: 
            postOrder(root);
            break;
        case 5:
            printf("Exited");
        default:
            printf("Invalid choice");
            break;
        }
    } while (select != 6);
}

