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
    void getInorder(TreeNode* root, vector<TreeNode*> &inorder){
        if(root == NULL)
            return;

        getInorder(root->left, inorder);
        inorder.push_back(root);
        getInorder(root->right, inorder);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        getInorder(root, inorder);

        TreeNode* first = NULL;
        TreeNode* second = NULL;
        bool flag = true;
        for(int i=1;i<inorder.size();i++){
            if((inorder[i]->val)<(inorder[i-1]->val)){
                if(flag){
                    first = inorder[i-1];
                    second = inorder[i];
                    flag = false;
                }
                else{
                    second = inorder[i];
                    break;
                }
            }
        }
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};