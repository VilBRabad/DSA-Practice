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
    //Destructor
    ~Node(){
        
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data<<" ";
        temp = temp->Next;
    }
    cout<<endl;
}

int main(){

    Node* node1 = new Node(10);
    Node*head = node1;

    print(head);

    return 0;
}