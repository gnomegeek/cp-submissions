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
string ff = "FastestFinger", ash = "Ashishgup";

void lego() {
    int n;
    cin >> n;
    if (n & 1 and n != 1) {
        cout << ash;
    } else if (n == 1) {
        cout << ff;
    } else if (n == 2) {
        cout << ash;
    } else {
        int k = 0, twocnt = 0;

        while (n % 2 == 0) {
            n /= 2;
            twocnt++;
        }
        if (n == 1) {
            cout << ff;
        } else {
            if (twocnt > 1) {
                cout << ash;
            } else {
                for (int i = 3; i * i <= n; i++) {
                    int f = 0;
                    while (n % i == 0) {
                        f = 1;
                        n /= i;
                        k++;
                    }
                    if (n == 1) break;
                    if (f) {
                        k = 2;
                        break;
                    }

                    if (k >= 2) break;
                }

                if (k > 1) {
                    cout << ash;
                } else {
                    cout << ff;
                }
            }
        }
    }

    cout << endl;
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