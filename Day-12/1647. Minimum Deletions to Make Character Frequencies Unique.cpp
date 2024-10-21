class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};

        for (int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        } 

        int res = 0;

        /*----------------------------------------------- Extra Space taking approach -------------------------------------*/

        // unordered_set<int> st;

        // for(int i=0;i<26;i++){
        //     while(freq[i]>0 && st.find(freq[i])!=st.end()){
        //         freq[i] -= 1;
        //         res++;
        //     }
        //     st.insert(freq[i]);
        // }

        /* ---------------------------------------------- Optimized Approach ----------------------------------------------*/

        sort(freq, freq+26);

        for(int i=24;i>=0 && freq[i]>0;i--){
            if(freq[i]>=freq[i+1]){
                int prev = freq[i];
                freq[i]=max(0,freq[i+1]-1);
                res += (prev-freq[i]);
            }
        }

        return res;
    }
};