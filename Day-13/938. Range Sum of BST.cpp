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
    void calculateInOrder(vector<int>& arr,TreeNode* root) {
        if (root == NULL) {
            return;
        }

        calculateInOrder(arr,root->left);
        arr.push_back(root->val);
        calculateInOrder(arr,root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> arr;
        calculateInOrder(arr,root);
        int i=0;
        for(i=0;i<arr.size();i++){
            if(arr[i] == low)
                break;
        }
        int sum = 0;
        while(i<arr.size()){
            sum += arr[i];
            if(arr[i]==high)
                break;
            i++;
        }
        return sum;
    }
};