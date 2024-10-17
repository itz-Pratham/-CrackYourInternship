class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        string res1 = "", res2 = "";

        for(int i=0;i<s.size();i++){
            if(s[i]!='#')
                s1.push(s[i]);
            else
                if(!s1.empty())
                    s1.pop();
        }
        while(!s1.empty()){
            res1 += s1.top();
            s1.pop(); 
        }

        for(int j=0;j<t.size();j++){
            if(t[j]!='#')
                s1.push(t[j]);
            else
                if(!s1.empty())
                    s1.pop();
        }
        while(!s1.empty()){
            res2 += s1.top();
            s1.pop(); 
        }

        return (res1 == res2);
    }
};