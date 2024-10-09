class Solution {
public:
    string reverseWords(string s) {

        int i=0;
        int j = s.size()-1;

        string str = "";
        string temp = "";

        bool flag_i = false;
        bool flag_j = false;

        while(i<=j){
            if(s[i]==' ')
                i += 1;
            else
                flag_i = true;
            
            
            if(s[j]==' ')
                j -= 1;
            else
                flag_j = true;
            
            
            if((flag_i==true) && (flag_j == true))
                break;
        }

        int count = 0;

        for (; j >= i; j--) {
            if (s[j] == ' ') {
                if (!str.empty()) { // Skip multiple spaces between words
                    if (count == 0) {
                        temp.append(str);
                        count++;
                    } else {
                        temp.append(' ' + str);
                    }
                    str = "";
                }
            } else {
                str = s[j] + str;
            }
        }

        if (!str.empty()) {
            if (count == 0) {
                temp.append(str);
            } else {
                temp.append(' ' + str);
            }
        }

        return temp;
    }
};