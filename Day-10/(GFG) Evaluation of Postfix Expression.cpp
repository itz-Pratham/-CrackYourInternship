class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        
        for(int i=0;i<S.size();i++){
            int second = -1;
            int first = -1;
            if(S[i] == '+'){
                if(!st.empty()){
                    second  = st.top();
                    st.pop();
                    first = st.top();
                    st.pop();
                    int temp = first + second;
                    st.push(temp);
                }
            }else if(S[i] == '-'){
                if(!st.empty()){
                    second  = st.top();
                    st.pop();
                    first = st.top();
                    st.pop();
                    int temp = first - second;
                    st.push(temp);
                }
            }else if(S[i] == '*'){
                if(!st.empty()){
                    second  = st.top();
                    st.pop();
                    first = st.top();
                    st.pop();
                    int temp = first * second;
                    st.push(temp);
                }
            }else if(S[i] == '/'){
                if(!st.empty()){
                    second  = st.top();
                    st.pop();
                    first = st.top();
                    st.pop();
                    int temp = first / second;
                    st.push(temp);
                }
            }else{
                st.push(S[i] - '0');
            }
        }
        return st.top();
    }
};