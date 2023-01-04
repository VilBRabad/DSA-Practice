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

//Same thing we can do using a class
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

int main(){

    struct node* root = new node(5);
    root->left = new node(6);
    root->right = new node(7);
    root->left->right = new node(9);
    root->left->left = new node(8);

    /*representation: of above code
                5
               / \
              6   7
             / \
            8   9
    */
    return 0;
}