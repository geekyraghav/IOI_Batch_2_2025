class Solution {
  public:
    vector<Node*> a;
    vector<Node*> b;
    void paths(Node* root, vector<Node*>& arr, int p, int q){
        if(root==NULL) return;
        arr.push_back(root);
        if(root->data == p) a = arr; // a me arr ki copy gayi hai
        if(root->data == q) b = arr; // a me arr ki copy gayi hai
        paths(root->left,arr,p,q);
        paths(root->right,arr,p,q);
        arr.pop_back();
    }
    int findDist(Node* root, int p, int q) {
        a.resize(0);
        b.resize(0);
        vector<Node*> arr;
        paths(root,arr,p,q);
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i]->data == b[j]->data){
                i++;
                j++;
            }
            else break;
        }
        return a.size() - i + b.size() - j;
    }
};
