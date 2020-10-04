#include <iostream>
#include <string>

using namespace std;

class circularQueue
{
private:
    int front,rear,itemCount;
    int arr[5];
public:
    circularQueue(){
        rear = -1;
        front = -1;
        itemCount = 0;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
        
    }

    bool isfull(){
        if((rear+1)%5 == front){
            return true;
            cout<<(rear+1)%5;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty(){
        if(rear == -1 && front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int val){
        if(isfull()){
            cout<<"The queue is full";
        }
        else if(isEmpty()){
            rear = front = 0;
        }
        else
        {
            rear = (rear+1)%5;
        }

        arr[rear] = val;
        itemCount++;
    }

    int dequeue(){
        int x = 0;
        if (isEmpty())
        {
            cout<<"Queue is empty";
            return 0;
        }
        else if(rear == front)
        {
            x = arr[front];
            rear = front = -1;
        }
        else
        {
            x=arr[front];
            arr[front]=0;
            front = (front+1)%5;
        }
        itemCount--;
        return x;
    }

    int count(){
        return itemCount;
    }

    void display(){
        for (int i = 0; i < 5; i++)
        {
            cout<<arr[i];
        }
        
    }
};

int main(){
    circularQueue q1;
    int option,val;
    do
    {   
        cout<<"Choose the operation that you want to do on stack (1-8)\n";
        cout<<"0. Exit\n";
        cout<<"1. Add an element(enqueue)\n";
        cout<<"2. remove an element(dequeue)\n";
        cout<<"3. Check if the queue is full??(isfull)\n";
        cout<<"4. Check if the queue is empty??(isEmpty)\n";
        cout<<"5. Count the elements in the queue(count)\n";
        cout<<"6. display all elements(display)\n";
        cout<<"7. Clear screen\n";
        cin>>option;
        switch (option)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter the element you want to add:";
                cin>>val;
                q1.enqueue(val);
                break;
            
            case 2:
                cout<<"The first element added in the queue is:";
                cout<<q1.dequeue();
                break;
    
            case 3:
                if(q1.isfull()){
                    cout<<"The queue is full\n";
                }
                else
                {
                    cout<<"the queue is not full yet\n";
                }
                
                break;
    
            case 4:
                if(q1.isEmpty()){
                    cout<<"The stack is empty\n";
                }
                else
                {
                    cout<<"the stack is ot empty\n";
                }
                
                break;
    
            case 5:
                cout<<"The total element in stack are: "<<q1.count();
                break;
                
            case 6:
                q1.display();
                break;
    
            case 7:
                system("cls");
                break;
            
            default:
                cout<<"Wrong option";
                break;
        }
    } while (option!=0);
    
    return 0;
}


