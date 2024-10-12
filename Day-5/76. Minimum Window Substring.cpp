class Solution {
public:
    string minWindow(string s, string t) {
        
        string ans="";
        if (t.size() > s.size()) return "";
        vector<int> hash(256,0);
        int l =0;
        int r=0;
        int m = s.size();
        int n = t.size();
        int minl = 1e5;
        int cnt  = 0;
        int si=-1;

        for(int i = 0 ;i<n; i++ ){
            hash[t[i]]++;
        }
        while(r<m){
            if(hash[s[r]]>0){
                cnt++;
                }
                
                hash[s[r]]--;
            
            while(cnt==n){
                if(r-l+1 < minl){
                    minl = r-l+1;
                si = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }

        if(si==-1){
            return ans;
        }

        return s.substr(si,minl);

    }
};