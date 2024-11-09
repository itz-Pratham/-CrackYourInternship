class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Node* temp = root;
        
        // Traverse to find the node with the given key
        while (temp != NULL && temp->key != key) {
            if (temp->key > key) {
                suc = temp;            // Update successor
                temp = temp->left;
            } else {
                pre = temp;            // Update predecessor
                temp = temp->right;
            }
        }
        
        // If key not found, return
        if (temp == NULL)
            return;
        
        // Finding predecessor (rightmost node in left subtree)
        if (temp->left != NULL) {
            Node* leftTree = temp->left;
            while (leftTree->right != NULL) {
                leftTree = leftTree->right;
            }
            pre = leftTree;
        }
        
        // Finding successor (leftmost node in right subtree)
        if (temp->right != NULL) {
            Node* rightTree = temp->right;
            while (rightTree->left != NULL) {
                rightTree = rightTree->left;
            }
            suc = rightTree;
        }
    }

};