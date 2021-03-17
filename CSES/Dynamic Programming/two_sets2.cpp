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

int fastpower(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) return fastpower((a % mod * a % mod) % mod, b / 2) % mod;
    return (a % mod * fastpower(a, b - 1) % mod) % mod;
}

int divide(int a, int b) { return a * fastpower(b, mod - 2) % mod; }

int dp[63000][501];

int twosets(int sum, int n) {
    if (sum == 0) return 1;
    if (n == 0 || sum < 0) return 0;

    if (dp[sum][n] != -1) return dp[sum][n] % mod;

    int include = twosets(sum - n, n - 1);
    int exclude = twosets(sum, n - 1);

    return dp[sum][n] = (include % mod + exclude % mod) % mod;
}

void lego() {
    int n, k, m, cnt = 0;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    memset(dp, -1, sizeof dp);
    int res;
    if (sum % 2 != 0)
        res = 0;
    else
        res = (twosets(sum / 2, n));

    cout << divide(res, 2) << endl;
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