class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    bool isBST(Node* root, long min, long max){
        if(root == nullptr)
            return true;

        if(root->data > min && root->data < max){
            return isBST(root->left, min, root->data) && 
                    isBST(root->right, root->data, max);
        } else {
            return false;
        }
    }
    
    int calculateSize(Node* root) {
        if (root == nullptr)
            return 0;
        return 1 + calculateSize(root->left) + calculateSize(root->right);
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	if(root == nullptr){
    	    return 0;
    	}
    	
    	 int largestBSTSize = 0;
    	 queue<Node*> q;
    	 q.push(root);
    	 
    	 
    	 while(!q.empty()){
    	     int size = q.size();
    	     
    	     for(int i=0;i<q.size();i++){
    	         Node* temp = q.front();
    	         q.pop();
    	         
    	         if (isBST(temp, LONG_MIN, LONG_MAX)) {
                    int currentSize = calculateSize(temp);
                    largestBSTSize = max(largestBSTSize, currentSize);
                 }
                 
    	         if(temp->left) q.push(temp->left);
    	         if(temp->right) q.push(temp->right);
    	     }
    	 }
    	 
    	 return largestBSTSize;
    }
};