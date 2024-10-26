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
    pair<int, int> computeDiameterEfficient(TreeNode* root) {

        pair<int, int> p; // <height, diameter>

        // base case
        if (root == NULL) {
            p.first = 0;
            p.second = 0;
            return p;
        }

        // recursive case

        pair<int, int> left = computeDiameterEfficient(root->left);
        pair<int, int> right = computeDiameterEfficient(root->right);
        int Z = left.first + right.first + 0; // here we would have added 1 if the no. of nodes
                                              // were required for calculating the diameter but here no.
                                              // of edges are required

        p.first = 1 + max(left.first, right.first);
        p.second = max({left.second, right.second, Z});

        return p;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        return computeDiameterEfficient(root).second;
    }
};