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
int dp[100003][6];

int score(int a[], int n, int i, int z, int k) {
    if (k < 0) return 0;
    if (i < 0) return -inf;
    if (i >= n) return -inf;

    if (dp[i][z] != -1) return dp[i][z];

    int op1, op2;
    if (z - 1 >= 0)
        op1 = a[i] + score(a, n, i - 1, z - 1, k - 1);
    else
        op1 = -inf;
    op2 = a[i] + score(a, n, i + 1, z, k - 1);
    return dp[i][z] = max(op1, op2);
}

void lego() {
    int n, k, z;
    cin >> n >> k >> z;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << score(a, n, 0, z, k) << endl;
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