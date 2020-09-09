/* Coded by NihalP01 */

#include<iostream>
#include<string>

using namespace std;

class Queue{
    private: 
        int front;
        int rear;
        int arr[5];
    public:
        Queue(){
            front = -1;
            rear = -1;
            for (int i = 0; i < 5; i++)
            {
                arr[i] = 0;
            }
        }
        bool isEmpty(){
            if (front == -1 && rear == -1)
            {
                return true;
            }else
            {
                return false;
            }
        }
        bool isFull(){
            if (rear == 4)
            {
                return true;
            }else
            {
                return false;
            }
        }
        void enqueue(int val){
                if (isFull())
                {
                    cout<<"Queue is Full"<<endl;
                    return;
                }else if(isEmpty()){
                    rear = front = 0;
                    arr[rear] = val;    
                }else
                {
                   rear++;
                   arr[rear] = val;
                }     
         }

        int dequeue(){
            int x;
            if (isEmpty())
            {
                cout<<"Queue is Empty";
            }
            else if(front==rear)
            {
                x = arr[front];
                arr[front] = 0;
                front = rear = -1;
                return x;
            }else
            {
                x = arr[front];
                arr[front] = 0;
                front++;
                return x;
            }
        }

        int count(){
            return rear-front+1; // (rear-front+1)= (2-0+1)=3
        }
        void display(){
            cout<<"All the values in the Queue are:"<<endl;
            for (int i = 0; i < 5; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        
};
int main(){
     Queue q1;
     int option, value;
    do
    {
        cout<<"\n\nWhat operations do you want to perform? Enter 0 to exit\n"<<endl;
            cout<<"1. Enqueue()"<<endl;
            cout<<"2. Dequeue()"<<endl;
            cout<<"3. isEmpty()"<<endl;
            cout<<"4. isFull"<<endl;
            cout<<"5. Count()"<<endl;
            cout<<"6. Display()"<<endl;
            cout<<"7. Clear Screen \n"<<endl;
            cin>>option;

        switch (option)
        {
        case 0: 
            break;
        case 1: 
            cout<<"Enter a value to Enqeue in the Queue:"<<endl;
            cin>>value;
            q1.enqueue(value);
            break;
        case 2:     
            cout<<"Dequeue operation is called. Dequeued value: "<<q1.dequeue()<<endl;
            break;    
        case 3: 
            if (q1.isEmpty())
            {
                cout<<"Queue is empty!\n"<<endl;
            }else
            {
                cout<<"Queue is not empty()"<<endl;
            }
            break;
        case 4: 
            if (q1.isFull())
            {
                cout<<"Queue is Full"<<endl;
            }else
            {
                cout<<"Queue is not Full"<<endl;
            }
            break;
        case 5: 
            cout<<"Total item in the Queue:"<<q1.count()<<endl;
            break;
        case 6: 
            q1.display();
            break;                
        case 7:
            system("clear");
            break;    
        default:
            cout<<"Please enter a valid option"<<endl;
            break;
        }

    } while (option!=0);

    return 0;    
}


