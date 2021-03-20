class Solution {
   public:
    int minAddToMakeValid(string s) {
        int p_open = 0, min_open = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                p_open++;
            else
                p_open--;

            min_open = min(min_open, p_open);
        }

        int p_close = 0, min_close = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(')
                p_close--;
            else
                p_close++;

            min_close = min(min_close, p_close);
        }

        int res = 0;
        if (min_close < 0) res += abs(min_close);

        if (min_open < 0) res += abs(min_open);

        return res;
    }
};