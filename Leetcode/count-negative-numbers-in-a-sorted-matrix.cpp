class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cur_row = 0;
        int res = 0;
        for (int j = c - 1; j >= 0; j--) {
            if (grid[cur_row][j] >= 0) {
                res += c - j - 1;
                cur_row++;
                j++;
            }

            if (cur_row >= r) break;
        }

        if (cur_row < r) {
            res += (r - cur_row) * c;
        }

        return res;
    }
};