class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        stack<int> st;
        int len = s.size();
        int currentNumber = 0;
        char operation = '+';        
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                if (operation == '-') {
                    st.push(-currentNumber);
                } else if (operation == '+') {
                    st.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};