
class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exponent = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                digit = true;
            }
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
                digit = false;
            }
            else if (c == '.') {
                if (dot || exponent) {
                    return false;
                }
                dot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (exponent || !digit) {
                    return false;
                }
                exponent = true;
                digit = false;
            }
            else {
                return false;
            }
        }

        return digit;
    }
};
