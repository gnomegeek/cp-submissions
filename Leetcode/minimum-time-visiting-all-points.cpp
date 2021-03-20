class Solution {
   public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        int x = 0;
        pair<int, int> p = {points[0][0], points[0][1]};
        for (auto i : points) {
            if (!x)
                x = 1;
            else {
                int oldx = p.first;
                int oldy = p.second;
                int curx = i[0];
                int cury = i[1];
                res += max(abs(curx - oldx), abs(cury - oldy));
                p = {curx, cury};
            }
        }

        return res;
    }
};