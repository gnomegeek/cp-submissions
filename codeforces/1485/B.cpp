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

void lego() {
    int n, q, k;
    cin >> n >> q >> k;
    int a[n + 2];
    int exclude[n + 2] = {0};
    int excludeSum[n + 2] = {0};
    a[0] = 0;
    a[n + 1] = k + 1;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        exclude[i] = a[i + 1] - a[i - 1] - 2;
    }

    // for (int i = 0; i < n + 2; i++) cout << exclude[i] << " ";
    // cout << endl;

    for (int i = 1; i <= n; i++) {
        excludeSum[i] = excludeSum[i - 1] + exclude[i];
    }

    while (q--) {
        int x, y;
        cin >> x >> y;

        // if (y - x == 1) {
        //     cout << (a[y] - 2 + k - a[x] - 1) << endl;
        //     continue;
        // }

        int res = excludeSum[y - 1] - excludeSum[x];
        res += (a[x + 1] - 2 + k - a[y - 1] - 1);
        cout << res << endl;
    }
}

signed main() {
    OJ();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    if (false)
        cin >> tt;
    while (tt--) lego();

    return 0;
}