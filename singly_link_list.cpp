#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    int data;
    Node* next;
    Node(){
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int val){
        key = k;
        data = val;
        next = NULL;
    }
};


class singly_link_list
{
public:
    Node* head;
    singly_link_list(){
        head = NULL;
    }

    singly_link_list(Node* n){
        head = n;
    }

    //check if particular node or not
    Node* nodeexist(int k){
        Node* temp = NULL;
        Node* ptr = head; //we have to traverse from head to the end
        while (ptr!=0)
        {
            if(ptr->key == k){
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    //apend the node to the list
    void appendNode(Node* n){
        if(nodeexist(n->key)!=NULL){
            cout<<"Node already exist";
        }
        else
        {
            if(head == NULL){
                head = n;
                cout<<"Node appended\n";
            }
            else
            {
                Node* ptr = head;
                //for updating ptr till end
                while (ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout<<"Node appended\n";
            }
        }
    }

    void prependNode(Node* n){
        if(nodeexist(n->key)!=NULL){
            cout<<"Node already exists";
        }
        else
        {
            n->next = head;
            head = n;
            cout<<"Node prepended\n";
        }
    }

    //k is the node key after which we want to add
    void insertNode(int k,Node* n){
        if(nodeexist(k)==NULL){
            cout<<"no node exists";
        }
        else
        {   
            if(nodeexist(n->key)!=NULL){
                cout<<"Node already exists";
            }
            else{
                Node* ptr = head;
                while (ptr!=0)
                {  
                    if(ptr->key == k){
                        n->next = ptr->next;
                        ptr->next = n;
                        cout<<"Node inserted\n";
                    }
                }
                }
        }
    }

    void deleteNode(int k){
        if(head == NULL){
            cout<<"linkde list already empty";
        }
        else if(head!=NULL)
        {   //if its a head node
            if(head->key == k){
                head = head->next;
                cout<<"Node UNLINKED";
            }
            //if thwe node is not head node
            else
            {
                Node* temp = NULL;
                Node* prev = head;
                Node* current = head->next;
                while (current!=NULL)
                {
                    if(current->key==k){
                        temp = current->next;
                        current = NULL;
                    }
                    else
                    {
                        prev = prev->next;
                        current = current->next;
                    }
                }
                if(temp!=NULL){
                    prev->next = temp->next;
                    cout<<"Node UNLINKED";
                }
                else
                {
                    cout<<"Node doesn't exists\n";
                }
            }
        }  
    }

    void updateNode(int k,int val){
        Node* ptr = head;
        if(nodeexist(k)!=NULL){
            ptr->data = val;
            cout<<"Successfully updated\n";
        }
        else
        {
            cout<<"Node doesn't exists";
        }
    }

    void print(){
        if(head==NULL){
            cout<<"Linked list is empty\n";
        }
        else
        {
            cout<<"The linked list is:\n";
            Node* ptr = head;
            while(ptr!=NULL){
                cout<<"Key:"<<ptr->key<<"\tvalue:"<<ptr->data<<"-->";
                ptr = ptr->next;
            }
        }
        
    }
};

int main(){
    singly_link_list s1;;
    int option;
    int key,key1,val;
    do
    {   
        cout<<"Choose the operation that you want to do on stack (1-8)\n";
        cout<<"0. Exit\n";
        cout<<"1. appendNode()\n";
        cout<<"2. prepareNode()\n";
        cout<<"3. insertNodeAfter()\n";
        cout<<"4. deleteNodeByKey()\n";
        cout<<"5. updateNodeByKey\n";
        cout<<"6. print\n";
        cout<<"7. Clear screen\n";
        cin>>option;
        Node* n = new Node();    //heap memory usage which means it will be throughout the code
        //if we use Node n then this is stack.
        switch (option)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter the key and the element you want to add at last:";
                cin>>key1>>val;
                n->key = key1;
                n->data = val;
                s1.appendNode(n);
                break;
            
            case 2:
                cout<<"Enter the key and the element you want to add at first:";
                cin>>key1>>val;
                n->key = key1;
                n->data = val;
                s1.prependNode(n);
                break;
    
            case 3:
                cout<<"Enter the key you after which you want to add the value:";
                cin>>key1;
                cout<<"Enter the key and the value you want to add:";
                cin>>key>>val;
                n->key = key;
                n->data = val; 
                s1.insertNode(key1,n);
                break;
    
            case 4:
                cout<<"Enter the keyof an element you want to delete:";
                cin>>key;
                s1.deleteNode(key);
                break;
    
            case 5:
                cout<<"Enter the key and the value you want to update:";
                cin>>key>>val;
                s1.updateNode(key,val);
                break;
                
            case 6:
                s1.print();
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

