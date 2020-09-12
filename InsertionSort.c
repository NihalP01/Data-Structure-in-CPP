/* ©️ Coded by NihalP01 */

#include<iostream>

void insertionSort(int arr[]){
    int key;
    int j;
    for (int i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    
    insertionSort(myArray);
    
    printf("\n\nSorted array is:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", myArray[i]);
        printf(" ");
    }
    return 0;
}