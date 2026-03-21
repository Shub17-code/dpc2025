#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int data;
    Node(int data){
        this->data = data;
        left=NULL;
        right=NULL;
    }
};

//function to build tree
Node* buildTree(vector<int> &arr) {
    if(arr.empty() || arr[0] == -1){ 
        return NULL;
    }
    Node* root = new Node(arr[0]);
    queue<Node*> q; 
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* current = q.front();
        q.pop();
        if (arr[i] != -1) {
            current->left = new Node(arr[i]); 
            q.push(current->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            current->right = new Node(arr[i]); 
            q.push(current->right);
        }
        i++;
    }
    return root;
}

bool check(Node *left,Node *right){
    if(left==NULL || right==NULL){
        return left==right;
    }
    if(left->data!=right->data){
        return false;
    }
    return check(left->left,right->right) && check(left->right,right->left); 
}
bool isSymmetric(Node*root){
    if(root==NULL) return true; 
    return check(root->left,root->right);
}
int main(){
    vector<int> arr={1,2,2,3,-1,-1,3}; //consider -1 as null
    Node *root= buildTree(arr);
    bool ans=isSymmetric(root);
    if(ans) cout<<"True";
    else cout<<"False";
    return 0; 
}