/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* r1, TreeNode* r2){
        if(r1 == NULL and r2 == NULL)
            return true;
        
        if(r1 and !r2 || r2 and !r1)
            return false;

        if(r1->val != r2->val)
            return false;
        
        bool leftCut = solve(r1->left,r2->right);
        bool rightCut = solve(r1->right,r2->left);

        if(leftCut and rightCut)
            return true;
        
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};