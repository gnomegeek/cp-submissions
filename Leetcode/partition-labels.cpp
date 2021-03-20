class Solution {
   public:
    vector<int> partitionLabels(string S) {
        int last[26];
        int cnt = 0;
        for (char ch : S) last[ch - 'a'] = cnt++;
        vector<int> res;
        int end = 0, currsize = 0;
        for (int i = 0; i < S.length(); i++) {
            end = max(end, last[S[i] - 'a']);
            currsize++;
            if (i == end) {
                res.push_back(currsize);
                currsize = 0;
            }
        }

        return res;
    }
};