class Solution {
  public:
    int n;
    int size(Node* root){
        if(root==NULL) return 0;
        return 1 + size(root->left) + size(root->right);
    }
    bool isMaxHeap(Node* root) {
        if(root==NULL) return true;
        int left = (root->left) ? root->left->data : INT_MIN;
        int right = (root->right) ? root->right->data : INT_MIN;
        if(root->data < left or root->data < right) return false;
        return isMaxHeap(root->left) and isMaxHeap(root->right);
    }
    bool isCBT(Node* root, int idx) {
        if(root==NULL) return true;
        if(idx > n) return false;
        return isCBT(root->left,2*idx) and isCBT(root->right,2*idx+1);
    }
    bool isHeap(Node* root) {
        n = size(root);
        return isMaxHeap(root) and isCBT(root,1);
    }
};
