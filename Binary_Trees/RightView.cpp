class Solution {
public:
    int levels(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
        int n = levels(root);
        queue<pair<TreeNode*,int>> q;
        vector<int> ans(n);
        if(root) q.push({root,0});
        while(q.size() > 0){
            pair<TreeNode*,int> front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int lvl = front.second;
            ans[lvl] = (node->val);
            if(node->left) q.push({node->left,lvl+1});
            if(node->right) q.push({node->right,lvl+1});
        }
        return ans;
    }
};
