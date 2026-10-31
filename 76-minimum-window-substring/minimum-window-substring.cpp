class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> freq(128, 0);

        // Store frequency of characters in t
        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;
        int required = t.size();

        for (int right = 0; right < s.size(); right++) {

            // Include current character
            if (freq[s[right]] > 0) {
                required--;
            }

            freq[s[right]]--;

            // When all characters are found
            while (required == 0) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};