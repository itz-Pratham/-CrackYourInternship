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
    pair<int,int> isBalancedEfficient(TreeNode* root){
        pair<bool,int> p; // check, height

        // base case
        if(root == NULL){
            p.first = true;
            p.second = 0;
            return p;
        }

        // recursive case

        pair<bool,int> left = isBalancedEfficient(root->left);
        pair<bool,int> right = isBalancedEfficient(root->right);
        int diff = abs(left.second - right.second) <= 1;

        if(left.first && right.first && diff){
            p.first = true;
            p.second = max(left.second,right.second) + 1;
        }
        else{
            p.first = false;
            p.second = max(left.second,right.second) + 1;
        }

        return p;
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedEfficient(root).first;
    }
};