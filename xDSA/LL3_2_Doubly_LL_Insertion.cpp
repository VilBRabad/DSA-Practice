#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* Prev;
    Node* Next;

    //Constructor
    Node(int d){
        this->data = d;
        this->Prev = NULL;
        this->Next = NULL;
    }
};

void insertAtTail(Node* &head, int d){
    Node* inputNode = new Node(d);
    inputNode->Prev = head;
    head->Next = inputNode;
    head = inputNode;
}
void insertAtHead(Node* &head, int d){
    Node* inputNode = new Node(d);
    head->Prev = inputNode;
    inputNode->Next = head;
    head = inputNode;
}

void printHead(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->Next;
    }
    cout<<endl;
}
void printTail(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->Next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(75);
    Node* head = node1;
    Node* Tail = node1;

    int n, x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        insertAtTail(Tail, x); //Run only this 
        insertAtHead(head, x); // or this
    }

    printHead(head);
    printTail(Tail);

    return 0;
}