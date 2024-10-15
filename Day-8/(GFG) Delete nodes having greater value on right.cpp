class Solution {
  public:
    Node *compute(Node *head) {
        Node *curr = head;
        Node* start = head;
        
        vector<int> arr;
        
        while(curr){
            arr.push_back(curr->data);
            curr = curr->next;
        }
        
        int j = arr.size()-1;
        vector<int> postSum(arr.size(),INT_MIN);
        int curMax = arr[j];
        
        for(j;j>=0;j--){
            curMax = max(curMax,arr[j]);
            postSum[j] = curMax;
        }
        
        Node *newHead = new Node(-1);
        Node *cur = newHead;
        
        for(int i=0;i<postSum.size();i++){
            if(postSum[i]==arr[i]){
                Node* temp = new Node(postSum[i]);
                cur->next = temp;
                cur = cur->next;
            }
        }
        return newHead->next;
    }
};