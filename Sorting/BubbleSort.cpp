/* ©️ Coded by NihalP01 */

#include<iostream>

void bubbleSort(int arr[]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    
}

int main(){
    int myArray[5];
    printf("\nEnter 5 random numbers:");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", & myArray[i]);
    }
    printf("\nUnsorted array is:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", myArray[i]);
        printf(" ");
    }
    
    bubbleSort(myArray);
    
    printf("\n\nSorted array is:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", myArray[i]);
        printf(" ");
    }
    return 0;
}
