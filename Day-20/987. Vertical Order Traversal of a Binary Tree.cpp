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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;

        if(root == NULL)
            return res;

        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val);

            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1,lvl+1)));

            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1,lvl+1)));
        }

        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                // Sorting lvl wise
                sort(q.second.begin(), q.second.end());
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }

        return res;
    }
};