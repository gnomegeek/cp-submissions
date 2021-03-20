class Solution {
   public:
    bool match(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        if (i == s.length() and j == p.length()) return true;

        if (i == s.length()) return false;
        if (j == p.length()) return false;

        if (dp[i][j] != -1) return dp[i][j];

        if (p[j] == '*') {
            int op1 = match(s, p, i + 1, j, dp);
            if (op1)
                return dp[i][j] = op1;
            else
                return dp[i][j] = match(s, p, i, j + 1, dp);
        }

        if (p[j] == '?') return dp[i][j] = match(s, p, i + 1, j + 1, dp);

        if (s[i] != p[j]) return dp[i][j] = false;

        return dp[i][j] = match(s, p, i + 1, j + 1, dp);
    }

    bool isMatch(string s, string p) {
        s = s + 'a';
        p = p + 'a';

        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1));

        for (int i = 0; i < s.size() + 1; i++) {
            for (int j = 0; j < p.size() + 1; j++) {
                memo[i][j] = -1;
            }
        }

        return match(s, p, 0, 0, memo);
    }
};