class Solution {
   public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                              int num_wanted, int use_limit) {
        vector<pair<int, int> > labval;

        for (int i = 0; i < labels.size(); i++)
            labval.push_back({values[i], labels[i]});

        sort(labval.rbegin(), labval.rend());

        map<int, int> labcnt;

        for (int i = 0; i < labels.size(); i++) labcnt[labels[i]] = 0;

        int res = 0, cnt = 0;
        for (int i = 0; i < labval.size(); i++) {
            int lab = labval[i].second;
            int val = labval[i].first;
            if (labcnt[lab] < use_limit and cnt < num_wanted) {
                cnt++;
                labcnt[lab]++;
                res += val;
            }
        }

        return res;
    }
};