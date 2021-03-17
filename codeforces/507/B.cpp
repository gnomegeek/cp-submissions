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
    int r, x, y, x1, y1;
    cin >> r >> x >> y >> x1 >> y1;

    double dis = (sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)));

    double disInOne = 2 * r;

    int total = ceil(dis / disInOne);

    cout << total << endl;
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