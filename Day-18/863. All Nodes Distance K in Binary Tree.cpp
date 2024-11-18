/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left){
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        getParent(root, parent);

        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target] = true;
        int cur_lvl = 0;
        while(!q.empty()){
            int size = q.size();
            if(cur_lvl++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left and !visited[cur->left]){
                    q.push(cur->left);
                    visited[cur->left] = true;
                }
                if(cur->right and !visited[cur->right]){
                    q.push(cur->right);
                    visited[cur->right] = true;
                }
                if(parent[cur] and !visited[parent[cur]]){
                    q.push(parent[cur]);
                    visited[parent[cur]] = true;
                }
            }
        }

        vector<int> res;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            res.push_back(cur->val);
        }
        return res;
    }
};