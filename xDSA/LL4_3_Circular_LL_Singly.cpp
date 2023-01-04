#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* Next;

    //Constructor
    Node(int d){
        this->data = d;
        this->Next = NULL;
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



void insertAtTail(Node* &Tail, int d){
    
    if(Tail == NULL){
        Node* temp = new Node(d);
        Tail = temp;
        Tail->Next = Tail;
    }
    Node* temp = new Node(d);
    Tail->Next = Tail;
    //Node* forward = Tail->Next;
    Tail->Next = temp;
    temp->Next = Tail;
    Tail = temp;
}

void print(Node* head){
    Node* temp = head;
    while(temp->Next != head){
        cout<<temp->data<<" ";
        temp = temp->Next;
    }
}

int main(){
    Node* node1 = new Node(33);
    Node* Tail = node1;
    Node* head = node1;

    insertAtTail(Tail, 44);
    print(head);

    return 0;
}