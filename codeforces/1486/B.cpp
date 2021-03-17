#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ump unordered_map
#define endl "\n"
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pb push_back

int x[5000], y[5000];

void oj() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

signed main() {
    oj();
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            for (int i = 0; i < n; i++) {
                int a, b;
                cin >> a >> b;
            }
            cout << 1 << endl;
        } else {
            for (int i = 0; i < n; i++) {
                cin >> x[i] >> y[i];
            }
            sort(x, x + n);
            sort(y, y + n);
            int resx = x[n / 2] - x[n / 2 - 1] + 1;
            int resy = y[n / 2] - y[n / 2 - 1] + 1;
            int res = resx * resy;
            cout << res << endl;
        }
    }
    return 0;
}