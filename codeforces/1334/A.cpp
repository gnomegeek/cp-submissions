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
    int n;
    cin >> n;
    int a = 0, b = 0, printed = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (printed == 0 and (x < a || y < b || x < y || (x - a < y - b))) {
            cout << "NO" << endl;
            printed = 1;
        }
        a = x;
        b = y;
    }
    if (!printed) {
        cout << "YES" << endl;
    }
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