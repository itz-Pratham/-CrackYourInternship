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
    void preorder(TreeNode* root,string str, vector<string> &res){
        if(root == NULL)
            return;
        
        if(root->right == NULL and root->left == NULL){
            str += to_string(root->val);
            res.push_back(str);
        }
        
        str += to_string(root->val) + "->";
        preorder(root->left,str,res);
        preorder(root->right,str,res);

        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string str = "";
        preorder(root,str,res);
        return res;
    }
};