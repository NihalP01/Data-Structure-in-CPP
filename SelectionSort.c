  
  /* ©️ Coded by NihalP01 */
  
 #include<iostream>

 void selectionSort(int arr[]){
 
  for (int i = 0; i < 4; i++)
    {
        int min = i;
        
        for (int j = i+1; j < 5; j++)
        {
            if (arr[j]<arr[min])  //accending order
            {
                min = j;
            }
            
        }
        if (min!=i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
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
    
    selectionSort(myArray);
    
    printf("\n\nSorted array is:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", myArray[i]);
        printf(" ");
    }
    return 0;
}   