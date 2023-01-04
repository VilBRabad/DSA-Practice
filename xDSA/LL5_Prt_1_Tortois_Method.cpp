#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        while(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }

};

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        int x = slow->data;
        return x;
    }
};

int main(){

    return 0;
}