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
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    int arr[6] = {x - y, x, y, y - x, -x, -y};
    // cout << arr[n % 6] % mod << endl;

    while (arr[n % 6] < 0) {
        arr[n % 6] += mod;
    }
    cout << arr[n % 6] % mod << endl;
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