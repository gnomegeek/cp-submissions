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
    int n, segs = 0, one = -1, zero = -1;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (one != a[i] and zero != a[i]) {
            if (i == n - 1) {
                segs++;
                continue;
            }
            int cur = a[i];
            int next = a[i + 1];
            if (next == one) {
                one = cur;
            } else {
                zero = cur;
            }
            segs++;
        } else if (one == a[i] and zero == a[i]) {
            continue;
        } else if (one == a[i]) {
            segs++;
            zero = a[i];
        } else {
            segs++;
            one = a[i];
        }
    }

    cout << segs << endl;
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