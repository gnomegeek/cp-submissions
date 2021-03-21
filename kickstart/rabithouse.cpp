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

void updateMat(vector<int>& v, int mat[301][301], int r, int c,
               set<vector<int>, greater<vector<int>>>& s) {
    int i = v[1];
    int j = v[2];

    if (i + 1 <= r) {
        if (abs(mat[i + 1][j] - mat[i][j]) > 1) {
            auto itr = s.find({mat[i + 1][j], i + 1, j});
            mat[i + 1][j] = mat[i][j] - 1;
            s.erase(itr);
            s.insert({mat[i][j] - 1, i + 1, j});
        }
    }

    if (i - 1 >= 1) {
        if (abs(mat[i - 1][j] - mat[i][j]) > 1) {
            auto itr = s.find({mat[i - 1][j], i - 1, j});
            mat[i - 1][j] = mat[i][j] - 1;
            s.erase(itr);
            s.insert({mat[i][j] - 1, i - 1, j});
        }
    }

    if (j - 1 >= 1) {
        if (abs(mat[i][j - 1] - mat[i][j]) > 1) {
            auto itr = s.find({mat[i][j - 1], i, j - 1});
            mat[i][j - 1] = mat[i][j] - 1;
            s.erase(itr);
            s.insert({mat[i][j] - 1, i, j - 1});
        }
    }

    if (j + 1 <= c) {
        if (abs(mat[i][j + 1] - mat[i][j]) > 1) {
            auto itr = s.find({mat[i][j + 1], i, j + 1});
            mat[i][j + 1] = mat[i][j] - 1;
            s.erase(itr);
            s.insert({mat[i][j] - 1, i, j + 1});
        }
    }
}

void letsGO(int test) {
    int r, c;
    cin >> r >> c;
    int mat[301][301], origmat[301][301];

    set<vector<int>, greater<vector<int>>> s;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> mat[i][j];
            origmat[i][j] = mat[i][j];
            s.insert({mat[i][j], i, j});
        }
    }

    while (!s.empty()) {
        vector<int> v = *(s.begin());
        s.erase(s.begin());
        updateMat(v, mat, r, c, s);
    }

    int res = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            res += abs(origmat[i][j] - mat[i][j]);
        }
    }

    cout << "Case #" << test << ": " << res << endl;
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