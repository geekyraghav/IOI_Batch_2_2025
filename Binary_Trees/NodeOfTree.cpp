#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

void print(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

void invert(Node* root){
    if(root == NULL) return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invert(root->left);
    invert(root->right);
}

int size(Node* root){
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}
int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}
int sum(Node* root){
    if(root == NULL) return 0;
    return root->val + sum(root->left) + sum(root->right);
}
int product(Node* root){
    if(root == NULL) return 1;
    return root->val * product(root->left) * product(root->right);
}
int maxInTree(Node* root){
    if(root == NULL) return INT_MIN;
    int left = maxInTree(root->left);
    int right = maxInTree(root->right);
    return max(root->val,max(left,right));
}
int minInTree(Node* root){
    if(root == NULL) return INT_MAX;
    int left = minInTree(root->left);
    int right = minInTree(root->right);
    return min(root->val,min(left,right));
}
int main(){
    Node* a = new Node(1); // root
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->right = f;
    f->left = g;
    cout<<size(a)<<endl;
    cout<<sum(a)<<endl;
    cout<<product(a)<<endl;
    cout<<maxInTree(a)<<endl;
    print(a);

    // cout<<a->val<<endl;
    // cout<<a->left->val<<endl;
    // cout<<a->right->val<<endl;
    // cout<<a->left->left->val<<endl;
    // cout<<a->left->right->val<<endl;
    // cout<<a->right->right->val<<endl;
    

}