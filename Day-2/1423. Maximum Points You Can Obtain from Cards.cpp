class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int ans=0;

        for(int i=0;i<k;i++){
            ans += cardPoints[i];
        }

        int total = ans;

        for(int i=k-1;i>=0;i--){
            total-=cardPoints[i];
            total+=cardPoints[n-k+i];

            ans = max(ans,total);
        }
        
        return ans;
    }
};