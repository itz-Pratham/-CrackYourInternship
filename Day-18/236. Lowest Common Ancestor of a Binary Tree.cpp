/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    TreeNode* lca(TreeNode* root, int n1, int n2){
        if(root == NULL)
            return NULL;
        
        if(root->val == n1 || root->val == n2)
            return root;
        
        TreeNode* leftAns = lca(root->left, n1, n2);
        TreeNode* rightAns = lca(root->right, n1, n2);
        
        if(leftAns != NULL and rightAns != NULL)
            return root;
            
        if(leftAns != NULL and rightAns == NULL)
            return leftAns;
            
        if(leftAns == NULL and rightAns != NULL)
            return rightAns;
            
        else
            return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p->val, q->val);
    }
};