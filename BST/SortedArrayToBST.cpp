class Solution {
  public:
    Node* convert(vector<int>& arr, int lo, int hi) {
        if(lo > hi) return NULL;
        int mid = (lo+hi)/2;
        Node* root = new Node(arr[mid]);
        root->left = convert(arr,lo,mid-1);
        root->right = convert(arr,mid+1,hi); 
        return root;
    }
    Node* sortedArrayToBST(vector<int>& arr) {
        return convert(arr,0,arr.size()-1);
    }
};
