#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
// #define int long long
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
    int a, b;
    cin >> a >> b;
    int d[101];
    int flag = 0;
    if (b == 1) {
        flag = 1;
    }

    for (int i = 0; i <= 100; i++) {
        int ac = a;
        int bc = b + i;
        int res = i;
        if (bc == 1) {
            res = 1;
            bc++;
        }
        while (ac != 0) {
            ac /= bc;
            res++;
        }

        d[i] = res;
    }
    int mn = d[0];
    for (int i = 1; i < 101; i++) mn = min(mn, d[i]);

    // if (b == 1) mn++;
    cout << mn << endl;
    return;
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