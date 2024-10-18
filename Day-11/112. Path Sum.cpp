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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // base case

        if (root == NULL) {
            return false;
        }

        if (root->left == NULL and root->right == NULL) {
            if (root->val == targetSum) {
                return true;
            }
            return false;
        }

        // recursive case

        // recursively, check if there exists a root-to-leaf path in the leftSubtree whose sum is equal to targetSum-root->val

        // recursively, check if there exists a root-to-leaf path in the rightSubtree whose sum is equal to targetSum-root->val

        return hasPathSum(root->left, targetSum - root->val) or hasPathSum(root->right, targetSum - root->val);
    }
};