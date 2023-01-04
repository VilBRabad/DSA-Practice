#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void pre_order(node* root){
    if(root == NULL)
        return;
    cout<<(root->data)<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

int main(){

    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    pre_order(root); //1 2 4 5 3 6 7
    
    return 0;
}