class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    void createMap(int in[], unordered_map<int, int> &NodeToIndex, int size){
        for(int i=0;i<size;i++){
            NodeToIndex[in[i]] = i;
        }
    }
    Node* solve(int pre[], int in[], int &index, unordered_map<int, int> NodeToIndex, int inorderStart, int inorderEnd, int size){
        if(index >= size || inorderStart > inorderEnd)
            return NULL;
            
        int num = pre[index++];
        Node* root = newNode(num);
        int pos = NodeToIndex[num];
        
        root->left = solve(pre, in, index, NodeToIndex, inorderStart, pos-1, size);
        root->right = solve(pre, in, index, NodeToIndex, pos+1, inorderEnd, size);
        
        return root;
    }
    Node* Bst(int pre[], int size) {
        // code here
        int in[size],i;
        for (i = 0; i < size; i++) {
            in[i] = pre[size - i - 1];
        }
        sort(in,in+size);
        unordered_map<int, int> NodeToIndex;
        createMap(in, NodeToIndex, size);
        int index = 0;
        Node* ans = solve(pre, in, index, NodeToIndex, 0, size-1, size);
        return ans;
    }
};