class Solution{
  public:
    
    bool contain(Node* root, long min, long max){
        // Base case: if we reach a leaf node
        if (root == nullptr)
            return false;
    
        if (root->left == nullptr && root->right == nullptr) {
            if (max - min == 2)
                return true;
        }
    
        // Recursively check left and right subtrees
        bool leftDeadEnd = contain(root->left, min, root->data);
        bool rightDeadEnd = contain(root->right, root->data, max);
    
        return leftDeadEnd || rightDeadEnd;
    }
    
    bool isDeadEnd(Node *root)
    {
        return contain(root, 0, LONG_MAX);
    }
};