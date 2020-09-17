#include<iostream>
using namespace std;

int LinearSearch(int n[], int s){
    int temp = -1;

    for (int i = 0; i < 5; i++)
    {
        if (n[i]==s)
        {
            cout<<"the number "<<s<<" is at position: "<<i+1<<"\n"<<endl;
            temp = 0;
            break;
        }
    }
    if (temp == -1) 
    {
        cout<<"Number not found\n";
    }
    return 0;
}

int main()
{
    int num[5], search;
    cout<<"Enter some numbers:";
    for (int i = 0; i < 5; i++)
    {
        cin>>num[i];
    }
    cout<<"Enter the number you want to Search: ";
    cin>>search;
    LinearSearch(num, search);
    return 0;
}
