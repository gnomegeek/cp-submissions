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
    int n, k, cnt = 1, res = 0;
    vector<int> ones;
    cin >> n >> k;
    ones.push_back(-k);
    while (cnt != n + 1) {
        char ch;
        cin >> ch;
        if (ch == '1') ones.push_back(cnt);
        cnt++;
    }
    ones.push_back(n + k + 1);

    for (int i = 1; i <= ones.size() - 1; i++) {
        int x, num, den, z;
        x = ones[i] - ones[i - 1] - 1;
        num = x - k;
        den = 1 + k;
        z = num % den;
        num -= z;
        res += (num / den);
    }

    // for (int i : ones) cout << i << " ";

    // cout << endl;

    cout << res << endl;
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