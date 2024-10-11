class Solution {
public:
    string convertToTitle(int num) {
        string ans;
        while(num>0){
            num--;
            int cur = num % 26;
            num /= 26;
            ans.push_back(cur + 'A');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};