class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Find maximum words that can fit in one line
            while (j < n &&
                   letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            int spaces = maxWidth - letters;

            string line = "";

            // Last line or only one word: left justified
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += " ";
                    }
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else {
                // Fully justified line
                int spacePerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];

                    int count = spacePerGap;

                    if (k - i < extraSpaces) {
                        count++;
                    }

                    line += string(count, ' ');
                }

                line += words[j - 1];
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};