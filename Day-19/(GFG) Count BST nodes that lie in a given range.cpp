class Solution{
public:
    void calculateInOrder(vector<int>& arr,Node* root) {
        if (root == NULL) {
            return;
        }

        calculateInOrder(arr,root->left);
        arr.push_back(root->data);
        calculateInOrder(arr,root->right);
    }
    int getCount(Node *root, int l, int h)
    {
        // your code goes here 
        vector<int> arr;
        calculateInOrder(arr,root);
        int i=0;
        for(i=0;i<arr.size();i++){
            if(arr[i] >= l)
                break;
        }
        int cnt = 0;
        while(i<arr.size()){
            cnt++;
            if(arr[i]>h)
                break;
            i++;
        }
        if(i == arr.size()) return cnt;
        else return cnt-1;
    }
};