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
    int n, sum = 0, mx = -inf;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    int k = (sum / (n - 1));
    if (sum % (n - 1) != 0) k++;
    cout << max(mx, k) * (n - 1) - sum << endl;
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