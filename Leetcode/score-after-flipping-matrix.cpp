class Solution {
   public:
    int matrixScore(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();

        for (int i = 0; i < r; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < c; j++) {
                    A[i][j] = !A[i][j];
                }
            }
        }

        for (int i = 0; i < c; i++) {
            int ones = 0, zeros = 0;
            for (int j = 0; j < r; j++) {
                if (A[j][i] == 1)
                    ones++;
                else
                    zeros++;
            }
            if (ones < zeros) {
                for (int j = 0; j < r; j++) {
                    A[j][i] = !A[j][i];
                }
            }
        }

        int res = 0;

        for (int i = 0; i < r; i++) {
            int cnt = 0;
            for (int j = c - 1; j >= 0; j--) {
                if (A[i][j] == 1)
                    res += pow(2, cnt++);
                else
                    cnt++;
            }
        }

        return res;
    }
};