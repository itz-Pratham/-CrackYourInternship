class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq;

        vector<int> res;

        for(int i=0;i<n;i++){
            // make space for nums[i] ... removing all the out of index front bounds
            while(!deq.empty() && deq.front()<= i-k){
                deq.pop_front();
            }

            // popping all small front elements
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }

            // pushing indexes in deque
            deq.push_back(i);

            // when we start getting results
            if(i >= k-1){
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};