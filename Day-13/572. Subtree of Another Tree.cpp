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
    bool ans = false;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        return (
            p->val == q->val &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right)
        );
    }
    void postorder(TreeNode* root,TreeNode* subroot){
        if(root == NULL)
            return; 

        postorder(root->left,subroot);
        if(ans) return;  // if leftSubTree gives True, return immediately
        
        postorder(root->right,subroot);
        if(ans) return;   // if rightSubTree gives True, return immediately

        if(root->val == subroot->val) ans = isSameTree(root,subroot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        postorder(root,subRoot);
        return ans;
    }
};