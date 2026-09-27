class Solution {
public:
    int dia;
    int levels(TreeNode* root) {
        if(root==NULL) return 0;
        int left = levels(root->left);
        int right = levels(root->right);
        dia = max(dia,left+right); // extra
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia = 0;
        levels(root);
        return dia;
    }
};
