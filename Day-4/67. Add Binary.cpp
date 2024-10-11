class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;

        int maxLength = max(a.size(), b.size());
        while (a.size() < maxLength) a = '0' + a;
        while (b.size() < maxLength) b = '0' + b;

        for (int i = maxLength - 1; i >= 0; i--) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            result = char(sum % 2 + '0') + result;
            carry = sum / 2;
        }

        if (carry) result = '1' + result;

        return result;
    }
};