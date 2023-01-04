#include<bits/stdc++.h>
using namespace std;

#define _null NULL

struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        data = x;
        left = _null;
        right = NULL;
    }
};

void post_order(node* root){
    if(root == NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    cout<<(root->data)<<" ";
}

int main(){

    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    post_order(root); //1 2 4 5 3 6 7
    
    return 0;
}