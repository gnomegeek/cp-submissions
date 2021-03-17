#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ump unordered_map
#define endl "\n"
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pb push_back

void oj() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void lego() {
    int n, x, y, cnt = 0, k, c, d, b, z, w;
    cin >> n;

    int extra = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = x;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] + extra < i) {
            cout << "NO" << endl;
            return;
        } else if (a[i] < i) {
            extra -= (i - a[i]);
            a[i] = i;
        } else {
            extra += (a[i] - i);
        }
    }

    if (extra < 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

signed main() {
    oj();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TT = 1;
    if (true) cin >> TT;
    while (TT--) lego();
}