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
    int n, x = 0, y = 0;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            x = i - 1;
            break;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            y = i + 1;
            break;
        }
    }

    if (x > y) {
        cout << "no" << endl;
        return;
    }

    for (int i = x; i <= (x + y) / 2; i++) {
        swap(a[i], a[y - i + x]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            cout << "no" << endl;
            return;
        }
    }

    cout << "yes\n"
         << x + 1 << " " << y + 1 << endl;
    return;

    return;
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