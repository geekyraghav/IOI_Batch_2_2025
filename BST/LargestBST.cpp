class Solution {
  public:
    long long maxSize;
    class Quad{
        public:
            long long size;
            long long max;
            long long min;
            bool isBST;
            Quad(long long size, long long max, long long min, bool isBST){
                this->max = max;
                this->min = min;
                this->isBST = isBST;
                this->size = size;
            }
    };
    Quad dfs(Node* root) {
            if(root == NULL) return Quad(0,LLONG_MIN,LLONG_MAX,true);
            Quad left = dfs(root->left);
            Quad right = dfs(root->right);
            long long val = root->data;
            long long size = 1 + left.size + right.size;
            long long mx = max(val,max(left.max,right.max));
            long long mn = min(val,min(left.min,right.min));
            bool isBST = (val > left.max && val < right.min) && left.isBST && right.isBST;
            if(isBST) maxSize = max(maxSize,size);
            return Quad(size,mx,mn,isBST);
        }
    int largestBst(Node *root) {
        maxSize = 0;
        Quad ans = dfs(root);
        return maxSize;
    }
};
