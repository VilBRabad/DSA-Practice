#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *Next;

    //Constuctor  
    Node(int data){
        this -> data = data;
        this -> Next = NULL;
    }

    //Destructor
    ~Node(){
        int value = this->data;
        while(this->Next != NULL){
            delete Next;
            this->Next = NULL;
        }
        cout<<"Now Memory is FREE"<<endl;
    }
};
 
void insertAtHead(Node* &head, int d){
    //Create new node
    Node* temp = new Node(d);
    temp -> Next = head;
    head = temp;
}

void insertAtTail(Node* &Tail, int d){
    //Create a new node
    Node* temp = new Node(d);
    Tail -> Next = temp;   
    Tail = temp;
}

void insertAtPosition(Node* Tail, Node* head, int position, int d){
    //Inserting at head
    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    
    
    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp -> Next;
        cnt++;
    }

    //Inserting at last
    if(temp->Next == NULL){
        insertAtTail(Tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> Next = temp ->Next;
    temp -> Next = nodeToInsert; 
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> Next;
    }
    cout<<endl;
}

int main(){
    
    Node* Node1 = new Node(10);
    //cout<<Node1 ->data <<endl;
    //cout<<Node1 ->Next<<endl;

    Node* head = Node1;
    Node* Tail = Node1;
    //Before Insert
    print(head);
    //Inserting 23
    //insertAtHead(head, 23);
    insertAtTail(Tail, 23);

    //After Insert
    print(head);

    //Inserting 10
    //insertAtHead(head, 10);
    insertAtTail(Tail, 10);
    print(head); 

    insertAtPosition(Tail, head, 3, 9);
    print(head);

    //checking position of head & tail
    cout<< "Head = "<<head->data<<endl;
    cout<< "Tail = "<<Tail->data<<endl;
    
    return 0;
}