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

    int numCameras = 0;

    int helper(TreeNode* root) {

        // base case

        if (root == NULL) {
            return 2; // isCovered + no Camera
        }

        // recursive case

        int leftStatus = helper(root->left);
        int rightStatus = helper(root->right);

        if (leftStatus == 0 || rightStatus == 0) {
            // install camera at the root node
            numCameras++;
            return 1; // isCovered + hasCamera
        }

        return leftStatus == 1 || rightStatus == 1 ? 2 : 0;

    }

    int minCameraCover(TreeNode* root) {
        int rootStatus = helper(root);

	if (rootStatus == 0) {
		numCameras++;
	}

	return numCameras;
    }
};