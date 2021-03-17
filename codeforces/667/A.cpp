/*
    Author: Vatsal Agarwal
    Birla Institute of Technology and Sciences, Pilani, Goa Campus

    Make it work, make it right, make it fast.
*/

#include <bits/stdc++.h>
using namespace std;
typedef int itn;
#define int long long
// #define inf INT_MAX
#define umap unordered_map<int, int>
#define endl "\n"
#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define mid(s, e) ((s + (e - s) / 2))
#define mod 1000000007
#define scArray(a, b) \
    for (int i = 0; i < b; i++) cin >> a[i]

const double pi = acos(-1);
void OJ() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// assign 1 to tt for testcases
int TT = 0;

void lego() {
    cout << fixed << setprecision(6);
    double d, h, v, e;
    cin >> d >> h >> v >> e;
    double t1, t2, t3;
    t1 = (double)v;
    t2 = (e * pi * d * d) / 4.0;
    t3 = (pi * d * d * h) / 4.0;

    if (t1 <= t2) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << t3 / (t1 - t2) << endl;
}

signed main() {
    OJ();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (TT) {
        cin >> TT;
        while (TT--) {
            lego();
        }
    } else
        lego();
}