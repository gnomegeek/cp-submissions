class Solution {
   public:
    int balancedString(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) m[s[i]]++;
        int flag = 0;
        for (auto i : m) {
            if (i.second != s.length() / 4) {
                flag = 1;
                break;
            }
        }

        if (!flag) return 0;

        int n = s.size();
        int res = n;
        int left = 0;
        for (int right = 0; right < n; right++) {
            m[s[right]]--;
            while (left <= right && m['Q'] <= n / 4 && m['W'] <= n / 4 &&
                   m['E'] <= n / 4 && m['R'] <= n / 4) {
                res = min(res, right - left + 1);
                m[s[left]] += 1;
                left++;
            }
        }
        return res;
    }
};