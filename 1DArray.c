/*Submitted by Nihal Buragohain*/


#include<stdio.h>

int arr[100],top = -1;

void insert(int val, int n){
    if (top>=n-1)
    {
        printf("The array is full\n");
    }
    else
    {
        top++;
        arr[top] = val;
    }
    
}

void delete(){
    if (top<=-1)
    {
        printf("The array is Empty\n");
    }
    else
    {
        printf("The element with value %d is deleted\n", arr[top]);
        top--;
    }
}

void display(){
    if (top>=0)
    {
        printf("The elements are: ");
        for (int i = top; i>=0; i--)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }else
    {
        printf("The array is Empty");
    }
}

void merge(){
    int arrOneSize, arrTwoSize, totalArrSize, arrOne[10], arrTwo[10], arrMerge[50];
    printf("Enter the size of the first array: ");
    scanf("%d", &arrOneSize);
    printf("Enter the %d elements of the Array: ", arrOneSize);
    for (int i = 0; i < arrOneSize; i++)
    {
        scanf("%d", &arrOne[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &arrTwoSize);
    printf("Enter the %d elements of the array: ", arrTwoSize);
    for (int i = 0; i < arrTwoSize; i++)
    {
        scanf("%d", &arrTwo[i]);
    }

    for (int i = 0; i < arrOneSize; i++)
    {
        arrMerge[i] = arrOne[i];
    }
    totalArrSize = arrOneSize + arrTwoSize;

    for (int i = 0, j = arrOneSize; j < totalArrSize && i< arrTwoSize; i++, j++)
    {
        arrMerge[j] = arrTwo[i];
    }
    printf("\n %d Array Elements After Merging \n", totalArrSize); 
 	for(int i = 0; i < totalArrSize; i++)
  	{
    	printf(" %d ",arrMerge[i]);
  	}
      printf("\n");

}

int main(){
    int select, value,n;
    printf("Enter the max size of the array: ");
    scanf("%d", &n);
    do
    {
        printf("Enter your choice: \n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Merge an element\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("Enter the value you want to insert: ");
            scanf("%d", &value);
            insert(value, n);
            break;
        case 2: 
            delete();
            break;
        case 3:
            merge();
            break;
        case 4: 
            display();    
            break;
        default:
            break;
        }

    } while (select != 5);
    
}
