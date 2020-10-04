#include <iostream>

using namespace std;

class Node
{
    public:
    int data,key;
    Node* previous;
    Node* next;
    Node(){
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int k,int d){
        key = k;
        data = d;
        previous = NULL;
        next = NULL;
    }
};


class doubly_linked_list
{
public:
    Node* head;
    doubly_linked_list(){
        head = NULL;
    }

    doubly_linked_list(Node* n){
        head = n;
    }

    Node* nodeexists(int k){
        Node* temp = NULL;
        Node* ptr = head;
        while (ptr!=0)
        {
            if(ptr->key == k){
                temp = ptr;
            }
            ptr = ptr->next;
        }

        return temp;
    }

    void appendNode(Node* n){
        if(nodeexists(n->key)!=NULL){
            cout<<"Node already exists\n";
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
                while (ptr!=0)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                ptr->previous = ptr;
                cout<<"Node appended\n";
                
            }
            
        }
        
    }

    void prependNode(Node* n){
        if(nodeexists(n->key)!=NULL){
            cout<<"Node already exists\n";
        }
        else
        {   
            head->previous = n;
            n->next = head;
            head = n;
            cout<<"Node prepended\n";
        }
        
    }

    void insertNode(int k,Node* n){
        Node* ptr = nodeexists(k);
        if(ptr==NULL){
            cout<<" No Node exists";
        }
        else
        {
            if (nodeexists(n->key)!=NULL)
            {
                cout<<"Node already exists";
            }
            else
            {
                Node* nextNode = ptr->next;
                if(nextNode == nullptr){
                    ptr->next = n;
                    n->previous = ptr;
                    cout<<"Node inserted\n";
                }
                else
                {
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;

                    cout<<"Node inserted\n";
                }
                
                
            }
            
        }
        
    }

    void deleteNode(int k){
        Node* ptr = nodeexists(k);
        if(ptr == NULL){
            cout<<"No node exists\n";
        }
        else
        {
            if(head->key == k){
                head = head->next;
                cout<<"Node UNLINKED";
            }
            else
            {
                Node* prev = ptr->previous;
                Node* nextNode = ptr->next;
                //deleting the end
                if(nextNode == NULL){
                    prev->next = NULL;
                    cout<<"Node 'UNLINKED\n";
                }
                //deleteing in between
                else
                {
                    prev->next = nextNode;
                    nextNode->previous = prev;
                    cout<<"Node UNLINKED\n";
                }


            }
        }
    }

    void updateNode(int k,int val){
        Node* ptr = nodeexists(k);
        if(ptr!=NULL){
            ptr->data = val;
            cout<<"Node value updated\n";
        }
        else
        {
            cout<<"Node not found\n";
        }
        
    }
            
        

    void print(){
        if(head == NULL){
            cout<<"No Node exists\n";
        }
        else
        {
            cout<<"The Node are:\n";
            Node* ptr = head;
            while (ptr!=0)
            {
                cout<<"key:"<<ptr->key<<" value:"<<ptr->data;
                ptr = ptr->next;
            }
            
        }
        
    }

};

int main(){
    doubly_linked_list s1;;
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
