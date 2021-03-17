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
    int a1, k;
    cin >> a1 >> k;
    while (--k) {
        int max_dig = -inf;
        int min_dig = inf;
        int copy = a1;
        while (copy != 0) {
            max_dig = max(max_dig, copy % 10);
            min_dig = min(min_dig, copy % 10);
            copy /= 10;
        }

        if (max_dig == 0 || min_dig == 0)
            break;

        a1 += max_dig * min_dig;
    }
    cout << a1 << endl;
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