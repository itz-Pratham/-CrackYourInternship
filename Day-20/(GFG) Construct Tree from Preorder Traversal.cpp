Node* buildTree(int n, int pre[], char preLN[], int &idx) {
    if(idx >= n) return NULL;
    
    // Create new node
    Node* root = new Node(pre[idx]);
    
    // If current node is internal, construct its children
    if(preLN[idx] == 'N') {
        idx++;
        root->left = buildTree(n, pre, preLN, idx);
        idx++;
        root->right = buildTree(n, pre, preLN, idx);
    }
    
    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[]) {
    int idx = 0;
    return buildTree(n, pre, preLN, idx);
}