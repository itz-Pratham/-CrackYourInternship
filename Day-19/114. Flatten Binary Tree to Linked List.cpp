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
    void flatten(TreeNode* root) {
        if (root == NULL) return;

        // Flatten the left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Store the original right subtree
        TreeNode* tempRight = root->right;

        // Move the left subtree to the right
        root->right = root->left;
        root->left = NULL;

        // Find the end of the new right subtree and attach the old right subtree
        TreeNode* curr = root;
        while (curr->right != NULL) {
            curr = curr->right;
        }
        curr->right = tempRight;
    }
};