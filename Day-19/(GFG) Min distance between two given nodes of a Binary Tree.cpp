class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int NodeDist(Node* root,int x,int dist){
        
        /* ------------------------------------DFS-------------------------- */ 
        
        // if(root == NULL){
        //     return -1;
        // }
        
        // if(root->data == x){
        //     return dist;
        // }
        
        // int left = NodeDist(root->left, x, dist + 1);
        // int right = NodeDist(root->right, x, dist + 1);
        
        // if(left != -1){
        //     return left;
        // }
        
        // return right;
        
        /* ------------------------------------BFS-------------------------- */
        
        queue<Node*> q;
        q.push(root);
        
        int lvl = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp->data == x) return lvl;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            lvl++;
        }
        
        return -1;
    }
    Node* lca(Node* root, int n1, int n2){
        if(root == NULL)
            return NULL;
        
        if(root->data == n1 || root->data == n2)
            return root;
        
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);
        
        if(leftAns != NULL and rightAns != NULL)
            return root;
            
        if(leftAns != NULL and rightAns == NULL)
            return leftAns;
            
        if(leftAns == NULL and rightAns != NULL)
            return rightAns;
            
        else
            return NULL;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* LCA = lca(root, a, b);
        int d1 = NodeDist(LCA, a, 0);
        int d2 = NodeDist(LCA, b, 0);
        
        return (d1 + d2);
    }
};