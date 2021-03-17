#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ump unordered_map
#define endl "\n"
#define pb push_back
#define all(x) x.begin(), x.end();
#define enter(a) \
    for (int i = 0; i < a.size(); i++) cin >> a[i];

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pii;
typedef unordered_map<int, int> upii;
typedef vector<vector<int>> vvi;

const int linf = 1e18;
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int maxn = 200050;

void oj() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dp[501][501];

int squares(int a, int b) {
    if (a == b || a == 0 || b == 0) return 0;
    if (a == 1) return b - 1;
    if (b == 1) return a - 1;

    if (a > b) swap(a, b);

    if (dp[a][b] != -1) return dp[a][b];

    int moves = linf;

    for (int i = 1; i <= b - 1; i++)
        moves = min(moves, 1 + squares(i, a) + squares(b - i, a));

    for (int i = 1; i <= a - 1; i++)
        moves = min(moves, 1 + squares(i, b) + squares(a - i, b));

    dp[a][b] = moves;
    dp[b][a] = moves;

    return moves;
}

void lego() {
    int n, k, m, a, b, cnt = 0;
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << squares(a, b);
}

signed main() {
    oj();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TT = 1;
    if (false) cin >> TT;
    while (TT--) lego();
}