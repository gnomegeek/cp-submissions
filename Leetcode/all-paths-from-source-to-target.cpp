class Solution {
   public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, int i, vector<int>& st) {
        if (i == graph.size() - 1) {
            st.push_back(i);
            res.push_back(st);
            return;
        }

        vector<int> stcopy;
        st.push_back(i);
        for (int j : st) stcopy.push_back(j);

        for (int j : graph[i]) {
            dfs(graph, j, st);
            st.clear();
            st.resize(0);
            for (int k : stcopy) st.push_back(k);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        for (auto i : graph[0]) {
            vector<int> st;
            st.push_back(0);
            dfs(graph, i, st);
        }

        return res;
    }
};