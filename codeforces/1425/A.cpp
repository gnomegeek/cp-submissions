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
    int c = 0, tc = 1;
    cin >> n;
    while (n != 0) {
        if (n > 8)
            if (n % 2 != 0) {
                n--;
                if (tc) c++;
            } else {
                if (n % 4 == 0) {
                    n--;
                    if (tc) c++;
                } else {
                    if (tc)
                        c += (n >> 1);
                    n = n >> 1;
                }
            }
        else {
            if (n % 2 == 0) {
                if (tc)
                    c += (n >> 1);
                n = n >> 1;
            } else {
                n--;
                if (tc) c++;
            }
        }
        tc = !tc;
    }
    cout << c << endl;
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