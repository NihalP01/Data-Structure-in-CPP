/* ©️ Coded by NihalP01 */

#include<iostream>
using namespace std;

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
    cout<<"Enter some numbers in random order: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cin>>myArray[i];
    }
    cout<<"\nUnsorted Array is:"<<endl;  
    for (int i = 0; i < 5; i++)
    {  
        cout<<myArray[i]<<" ";
    }
    cout<<" "<<endl;

    selectionSort(myArray);

    cout<<"\nSorted Array is:"<<endl;  
    for (int i = 0; i < 5; i++)
    {  
        cout<<myArray[i]<<" ";
    }
    cout<<" "<<endl;    
   
    return 0;
}