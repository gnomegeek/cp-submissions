class Solution {
   public:
    void dfs(unordered_map<int, vector<int>> &ap, int i, vector<int> &res,
             map<int, bool> &visited) {
        visited[i] = true;

        for (auto j : ap[i]) {
            if (!visited[j]) {
                dfs(ap, j, res, visited);
            }
        }
        res.push_back(i);
    }

    vector<int> restoreArray(vector<vector<int>> &AP) {
        unordered_map<int, vector<int>> ap;

        for (auto i : AP) ap[i[0]].push_back(i[1]), ap[i[1]].push_back(i[0]);

        int start;
        for (auto i : ap) {
            if (i.second.size() == 1) {
                start = i.first;
                break;
            }
        }

        map<int, bool> visited;
        for (auto i : AP) {
            for (auto j : i) {
                visited[j] = false;
            }
        }

        vector<int> res;
        dfs(ap, start, res, visited);
        return res;
    }
};