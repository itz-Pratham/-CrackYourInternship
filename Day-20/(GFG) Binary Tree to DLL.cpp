class Solution {
  public:
    Node* head = NULL;
    Node* temp = NULL;
    void helper(Node* root){
        if(root == NULL)
            return;
        
        helper(root->left);
        
        if(temp == NULL){
            head = root;
        }
        else{
            temp->right = root;
            root->left = temp;
        }
        
        temp = root;
        
        helper(root->right);
        
    }
    Node* bToDLL(Node* root) {
        // code here
        if(root == NULL)
            return NULL;
        
        helper(root);
        
        return head;
    }
};