
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> phone = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;

        backtrack(digits, 0, current, result, phone);

        return result;
    }

private:
    void backtrack(string& digits, int index, string& current,
                   vector<string>& result, vector<string>& phone) {
        // All digits have been processed
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters corresponding to the current digit
        string letters = phone[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);

            backtrack(digits, index + 1, current, result, phone);

            // Undo the choice to try the next letter
            current.pop_back();
        }
    }
};
