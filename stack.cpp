/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
    int top;
    int arr[5];
public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
        
    }
    bool isEmpty()
    {
        if(top==-1){
            return true;
        }
        else
        {
            return false;
        }   
    }
    bool isfull(){
        if (top == 4)
        {
            return true;
        }
        else
        {
            return false;
        }   
    }

    void push(int val){
        if (isfull()) cout<<"Stack overflow";
        else
        {
            top++;
            arr[top] = val;
        } 
    }

    int pop(){
        if(isEmpty()) {
            cout<<"Stack underflow";
            return 0;
            }
        else
        {
            int pop_val = arr[top];
            arr[top] = 0;
            top--;
            return pop_val;
        } 
    }

    int count(){
        return top+1;
    }

    int peek(int pos){
        if(isEmpty()) {
            cout<<"Stack underflow";
            return 0;
            }
        else
        {
            return arr[pos];
        }      
    }

    void change(int pos, int val){
        arr[pos] = val;
        cout<<"value at "<<pos<<" has changed";
    }

    void display(){
        cout<<"All values are:\n";
        for (int i = 4; i >=0; i++)
        {
            cout<<arr[i]<<"\n";
        }
        
    }
};

int main(){
    Stack s1;
    int option,pos,val;
    do
    {   
        cout<<"Choose the operation that you want to do on stack (1-8)\n";
        cout<<"0. To Exit";
        cout<<"1. Add an element(push)\n";
        cout<<"2. pop out an element(pop)\n";
        cout<<"3. Check if the stack is full??(isfull)\n";
        cout<<"4. Check if the stack is empty??(isEmpty)\n";
        cout<<"5. Count the elements in the stack(count)\n";
        cout<<"6. get particular element(peek)\n";
        cout<<"7. change an element(change)\n";
        cout<<"8. display all elements(display)\n";
        cout<<"9. Clear screen";
        cin>>option;
        switch (option)
        {
            case 0:
                break;
                
            case 1:
                cout<<"Enter the element you want to add:";
                cin>>val;
                s1.push(val);
                break;
            
            case 2:
                cout<<"The last element added in the stack is:";
                cout<<s1.pop();
                break;

            case 3:
                if(s1.isfull()){
                    cout<<"The stack is full";
                }
                else
                {
                    cout<<"the stack is not full yet";
                }
                
                break;

            case 4:
                if(s1.isEmpty()){
                    cout<<"The stack is empty";
                }
                else
                {
                    cout<<"the stack is ot empty";
                }
                
                break;

            case 5:
                cout<<"The total element in stack are: "<<s1.count();
                break;

            case 6:
                cout<<"Enter the position of the element you want:";
                cin>>pos;
                cout<<"the element at the postion "<<pos<<" is "<<s1.peek(pos);
                break;

            case 7:
                cout<<"Enter the element you want to change:";
                cin>>pos;
                cout<<endl;
                cout<<"Enter the value you want to replace:";
                cin>>val;
                s1.change(pos,val);
                break;

            case 8:
                s1.display();
                break;

            case 9:
                system("cls");
                break;
            
            default:
                cout<<"Wrong option";
                break;
        }
    } while (option!=0);
    
    return 0;
}