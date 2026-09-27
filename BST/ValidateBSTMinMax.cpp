class Solution {
public:
    class Triplet{
    public:
        long long min;
        long long max;
        bool isBST;
        Triplet(long long max, long long min, bool isBST){
            this->min = min;
            this->max = max;
            this->isBST = isBST;
        }
    };

    Triplet fun(TreeNode* root){
        if(root==NULL) return Triplet(LLONG_MIN,LLONG_MAX,true);
        Triplet left = fun(root->left);
        Triplet right = fun(root->right);
        long long val = root->val;
        long long mx = max(val,max(left.max,right.max));
        long long mn = min(val,min(left.min,right.min));
        bool isBST = (val > left.max && val < right.min) && (left.isBST && right.isBST);
        return Triplet(mx,mn,isBST);
    }

    bool isValidBST(TreeNode* root) {
        Triplet ans = fun(root);
        return ans.isBST;
    }
};
