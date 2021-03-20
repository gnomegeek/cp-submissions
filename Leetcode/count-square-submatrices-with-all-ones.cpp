class Solution {
   public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 1) {
                    cnt++;
                    for (int side = 2; side <= min(r - i, c - j); side++) {
                        bool ok = true;
                        for (int row = i; row <= i + side - 1; row++) {
                            if (matrix[row][j + side - 1] == 0) {
                                ok = false;
                                break;
                            }
                        }

                        for (int col = j; col <= j + side - 1; col++) {
                            if (matrix[i + side - 1][col] == 0) {
                                ok = false;
                                break;
                            }
                        }

                        if (ok) {
                            cnt++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        return cnt;
    }
};