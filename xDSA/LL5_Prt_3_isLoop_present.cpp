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
};

void loopHere(Node* head, Node* tail, int position){
    if(position == 0){
        return;
    }
    Node* walk = head;
    for(int i=0; i<position; i++){
        walk = walk->next;
    }
    tail->next = walk;
}

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {   
        if(head == NULL || head->next == NULL){
            return false;
        }
        
        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};