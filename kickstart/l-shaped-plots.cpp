#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

const int LINF = 1e18;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const int MOD2 = 998244353;

int gcd(int a, int b), lcm(int a, int b), expo(int e, int n);

bool cases = true;

void letsGO(int test) {
    int r, c;
    cin >> r >> c;
    int mat[r + 1][c + 1];

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<vector<int> > > info(
        r + 1, vector<vector<int> >(c + 1, vector<int>(4)));
    // info[r][c][3] up, down, right, left

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (mat[i][j] != 0) {
                if (j == 1) {
                    info[i][j][3] = 1;
                } else {
                    info[i][j][3] = info[i][j - 1][3] + 1;
                }
                if (i == 1) {
                    info[i][j][0] = 1;
                } else {
                    info[i][j][0] = info[i - 1][j][0] + 1;
                }
            } else {
                info[i][j][0] = 0;
                info[i][j][1] = 0;
                info[i][j][2] = 0;
                info[i][j][3] = 0;
            }
        }
    }

    for (int i = r; i >= 1; i--) {
        for (int j = c; j >= 1; j--) {
            if (mat[i][j] != 0) {
                if (j == c) {
                    info[i][j][2] = 1;
                } else {
                    info[i][j][2] = info[i][j + 1][2] + 1;
                }

                if (i == r) {
                    info[i][j][1] = 1;
                } else {
                    info[i][j][1] = info[i + 1][j][1] + 1;
                }
            } else {
                info[i][j][0] = 0;
                info[i][j][1] = 0;
                info[i][j][2] = 0;
                info[i][j][3] = 0;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int up = info[i][j][0];
            int down = info[i][j][1];
            int right = info[i][j][2];
            int left = info[i][j][3];
            if (right >= 2 and up >= 4) cnt += min(up / 2, right) - 1;
            if (right >= 4 and up >= 2) cnt += min(right / 2, up) - 1;
            if (left >= 2 and up >= 4) cnt += min(up / 2, left) - 1;
            if (left >= 4 and up >= 2) cnt += min(left / 2, up) - 1;
            if (left >= 2 and down >= 4) cnt += min(down / 2, left) - 1;
            if (left >= 4 and down >= 2) cnt += min(left / 2, down) - 1;
            if (right >= 2 and down >= 4) cnt += min(down / 2, right) - 1;
            if (right >= 4 and down >= 2) cnt += min(right / 2, down) - 1;
        }
    }

    cout << "Case #" << test << ": " << cnt << endl;
}

void speeeeeeeeeed() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int expo(int e, int n) {
    return n ? n & 1 ? e * expo(e, --n) : expo(e * e, n / 2) : 1;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

signed main() {
    speeeeeeeeeed();
    cout << fixed << setprecision(10);
    int TT = 1, cnt = 0;
    if (cases) cin >> TT;
    while (TT--) letsGO(++cnt);
}