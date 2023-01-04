#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return (1 + max(lh, rh));
    }
};

int main(){

    
    

    return 0;
}