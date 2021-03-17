#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define int long long
#define ump unordered_map
#define endl "\n"
#define mod 1000000007

void OJ() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dp[300001][2];

int solve(int a[], int i, int n, int sign) {
    if (i == n) return 0;
    int op1, op2;
    if (dp[i][sign] != -1) return dp[i][sign];
    if (sign) {
        op1 = solve(a, i + 1, n, sign);
        op2 = solve(a, i + 1, n, !sign) + a[i];
    } else {
        op1 = solve(a, i + 1, n, sign);
        op2 = solve(a, i + 1, n, !sign) - a[i];
    }

    return dp[i][sign] = max(op1, op2);
}

void lego() {
    int n, qpwe;
    cin >> n >> qpwe;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    if (n == 2) {
        cout << max(a[0], a[1]) << endl;
        return;
    }
    memset(dp, -1, sizeof dp);

    cout << solve(a, 0, n, 1) << endl;
}

signed main() {
    OJ();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    if (true)
        cin >> tt;
    while (tt--) lego();

    return 0;
}