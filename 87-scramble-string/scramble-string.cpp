
class Solution {
public:
    unordered_map<string, bool> dp;

    bool solve(string s1, string s2) {
        int n = s1.size();

        // If both strings are equal
        if (s1 == s2) return true;

        // If lengths are different
        if (n != s2.size()) return false;

        // Check memoization
        string key = s1 + "#" + s2;

        if (dp.find(key) != dp.end())
            return dp[key];

        // Check if character frequencies differ
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b)
            return dp[key] = false;

        // Try every possible partition
        for (int i = 1; i < n; i++) {

            // Case 1: No swapping
            bool noSwap =
                solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i));

            if (noSwap)
                return dp[key] = true;

            // Case 2: Swapping
            bool swap =
                solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i));

            if (swap)
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        dp.clear();
        return solve(s1, s2);
    }
};
