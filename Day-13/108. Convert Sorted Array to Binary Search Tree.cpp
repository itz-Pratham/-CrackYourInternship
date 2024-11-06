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
    TreeNode* buildBBST(vector<int> A, int s, int e) {

        if (s > e) {
            return NULL;
        }

        int m = s + (e - s) / 2;
        TreeNode* root = new TreeNode(A[m]);
        root->left = buildBBST(A, s, m - 1);
        root->right = buildBBST(A, m + 1, e);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = buildBBST(nums, 0, n - 1);
        return root;
    }
};