#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    //Constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    
    //Destructor
    ~Node(){
        int value = this->data;
        while(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Now Memory is FREE"<<endl;
    }

};

class Solution1{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {   
        Node* newHead =NULL;
        while(head != NULL){
            Node* Next = head->next;
            head->next = newHead;
            newHead = head;
            head = Next;
        }
        return newHead;
    }
    
};

//Using Recursion
class Solution2{
    public:
    //Function to reverse a linked list
    Node* helper(Node* head, Node* newHead){
        if(head == NULL){
            return newHead;
        }
        Node* Next = head->next;
        head->next = newHead;
        newHead = head;
        head = Next;
        helper(head, newHead);
    }
    struct Node* reverseList(struct Node *head)
    {   
        Node* newHead = NULL;
        return helper(head, newHead);
    }
    
};


int main(){

    return 0;
}