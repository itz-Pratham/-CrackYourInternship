class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        vector<int> pos;
        vector<int> neg;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0)
                neg.push_back(nums[i]);
            else 
                pos.push_back(nums[i]);
        }

        sort(pos.begin(), pos.end(), greater<int>());
        sort(neg.begin(), neg.end());

        int maxProduct = INT_MIN;

        if(pos.size()>=3){
            maxProduct = pos[0]*pos[1]*pos[2];
        }

        if(pos.size()>=1 and neg.size()>=2){
            maxProduct = max(maxProduct,pos[0]*neg[0]*neg[1]);
        }

        if(pos.size() == 0 and neg.size()>=3){
            maxProduct =  neg[neg.size()-1]*neg[neg.size()-2]*neg[neg.size()-3];
        }

        return maxProduct;
    }
};