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

int minFactor(int n, int k) {
    int root = sqrt(n);
    vector<int> v;
    int last;
    for (int i = 1; i <= root; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i * i != n)
                v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    for (auto i = --v.end(); i != --v.begin(); i--) {
        if (*i <= k) {
            return n / (*i);
        }
    }
}

void lego() {
    int n, k;
    cin >> n >> k;

    if (k >= n) {
        cout << 1;
    } else {
        if (n % 2 == 0) {
            cout << minFactor(n, k);
        } else {
            cout << minFactor(n, k);
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