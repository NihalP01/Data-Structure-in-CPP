/*######Coded by NihalP01#######*/

#include <iostream>
#include <string>

using namespace std;

class Stack{
    private:
     int top;
     int arr[5];
    public:
      Stack(){
          top = -1;
          for(int i=0;i<5;i++){
              arr[i]= 0;
          }
      }
      bool isEmpty(){
          if(top==-1){
              return true;
             
          }else
          {
              return false;
          }
      }
      bool isFull(){
          if(top==4){
              return true;
          }else
          {
              return false;
          }
      }
      void push(int val){
          if(isFull()){
              cout<<"Stack Overflow"<<endl;
          }else{
              top++;
              arr[top]= val;
          }
      }
      int pop(){
         if (isEmpty())
         {
             cout<<"Stack Underflow"<<endl;
             return 0;
         }else
         {
             int popValue = arr[top];
             arr[top] = 0;
             top--;
             return popValue;
         }
         }
       int count()
       {
        return (top+1);
       }  
     int peek(int pos){
         if(isEmpty()){
             cout<<"Stack Underflow";
             return 0;
         }
         else
         {
             return arr[pos];
         }
     }  
     void change(int position, int value){
         arr[position]= value;
         cout<<"Value changed at the location"<<position<<endl;
     }
     void display(){
         cout<<"All the items in the stack are\n"<<endl;
         for(int i =4;i>=0;i--){
             cout<<arr[i]<<endl;
         }
     }

};
    int main(){
        Stack s1;
        int option, position, value;
        do{
            cout<<"What operations do you want to perform? Enter 0 to exit"<<endl;
            cout<<"1. PUSH()"<<endl;
            cout<<"2. POP()"<<endl;
            cout<<"3. isEmpty()"<<endl;
            cout<<"4. isFull"<<endl;
            cout<<"5. Peek()"<<endl;
            cout<<"6. Count()"<<endl;
            cout<<"7. Change()"<<endl;
            cout<<"8. Display()"<<endl;
            cout<<"9. Clear Screen \n"<<endl;
            cin>>option;
        
            switch (option)
            {
            case 0:
                break;
            case 1:
                cout<<"Enter the value to push in the stack:"<<endl;
                cin>>value;
                s1.push(value);
                cout<<"Done!\n"<<endl;
                break;
            case 2:
                cout<<"Pop funtion is called. Poped Value is: "<<s1.pop()<<endl;
                break;
            case 3:
                if(s1.isEmpty()){
                    cout<<"Stack is empty\n"<<endl;
                }else{
                    cout<<"Stack is not empty\n"<<endl;
                }
                break;
            case 4:
                if (s1.isFull())
                {
                    cout<<"Stack is full\n"<<endl;
                }else
                {
                    cout<<"Stack is not full\n"<<endl;
                }
                break;
            case 5:
                cout<<"Enter the position of item you want to peek:"<<endl;
                cin>>position;
                cout<<"Value at"<<position<<" is "<<s1.peek(position)<<endl;
                break;
            case 6:
               cout<<"Total items in the stack is:"<<s1.count()<<endl;
               break;
            case 7:
               cout<<"Enter the position you want to change:"<<endl;
               cin>>position;
               cout<<"Enter the value for the position "<<position<<endl;
               cin>>value;
               s1.change(position, value);
               cout<<"Done!"<<endl;
               break;
            case 8:
                s1.display();
                break;
            case 9:
               system("cls");
               break;    
            default:
                cout<<"Enter a valid option!"<<endl;
                break;
            }
        
        }while(option!=0);
        
        return 0;
     }
      


