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
    void inorder(TreeNode* root, int &sum, bool isleft){
        if(root== NULL){
            return;
        }

        inorder(root->left,sum,1);
        // left leaf
        if(root->left==NULL and root->right==NULL and isleft) sum+= root->val;
        inorder(root->right,sum,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        inorder(root, sum, 0);
        return sum;
    }
};