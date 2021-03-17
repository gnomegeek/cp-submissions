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
    int n, k;
    cin >> n >> k;
    int w[k], a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> w[i];

    sort(a, a + n);
    sort(w, w + k);
    int ones = 0;
    for (int i = 0; i < k; i++) {
        if (w[i] == 1) ones++;
    }

    int i = n - 1, j = 0, m = k - 1, happiness = 0, cnt = 0;

    while (cnt != ones) {
        happiness += 2 * a[i];
        i--;
        cnt++;
    }

    while (m != (ones - 1)) {
        int right = a[i], left = a[j];
        happiness += (left + right);
        i--;
        j += (w[m] - 1);
        m--;
    }

    cout << happiness << endl;
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