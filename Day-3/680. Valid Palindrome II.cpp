class Solution {
public:
    bool removing_one_element(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();

        int i=0;
        int j=n-1;

        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return removing_one_element(s,i+1,j) or removing_one_element(s,i,j-1);
            }
        }
        return true;


    }
};