void inorder(Node* root, vector<float> &in){
    if(root == NULL)
        return; 

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
float findMedian(struct Node *root)
{
      //Code here
      vector<float> in;
      inorder(root,in);
      
      int n = in.size();
      
      if(n%2 != 0)
        return in[n/2];
    
      return (in[n/2] + in[(n/2)-1])/2;
      
}