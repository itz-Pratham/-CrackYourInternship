class Solution {
public:
    int evalRPN(vector<string>& S) {
        stack<int> st;
        
        for(int i=0;i<S.size();i++){
            int second = -1;
            int first = -1;
            if(S[i] == "+"){
                if(!st.empty()){
                    second  = st.top();
                    st.pop();
                    first = st.top();
                    st.pop();
                    int temp = first + second;
                    st.push(temp);
                }
            }else if(S[i] == "-"){
                if(!st.empty()){
                    second  = st.top();
                    st.pop();
                    first = st.top();
                    st.pop();
                    int temp = first - second;
                    st.push(temp);
                }
            }else if(S[i] == "*"){
                if(!st.empty()){
                    second  = st.top();
                    st.pop();
                    first = st.top();
                    st.pop();
                    int temp = first * second;
                    st.push(temp);
                }
            }else if(S[i] == "/"){
                if(!st.empty()){
                    second  = st.top();
                    st.pop();
                    first = st.top();
                    st.pop();
                    int temp = first / second;
                    st.push(temp);
                }
            }else{
                st.push(stoi(S[i]));
            }
        }
        return st.top();
    }
};