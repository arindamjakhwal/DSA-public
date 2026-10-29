
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int> fact(n + 1, 1);
        string result;

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            nums.push_back(i);
        }

        k--; // Convert to 0-based indexing

        for (int i = n; i >= 1; i--) {
            int index = k / fact[i - 1];

            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            k %= fact[i - 1];
        }

        return result;
    }
};
