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
    ump<int, vector<int>> list;

    for (int i = 1; i <= n; i++) {
        list[i] = {};
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        list[x].push_back(y);
        list[y].push_back(x);
    }

    vector<int> leafs;

    for (auto i : list) {
        if (i.second.size() == 1) {
            leafs.push_back(i.first);
            if (i.first == k) {
                cout << "Ayush" << endl;
                return;
            }
        }
    }

    if (n == 1 || n == 2) {
        cout << "Ayush" << endl;
        return;
    }

    if (n % 2 == 0) {
        cout << "Ayush" << endl;
        return;
    }
    cout << "Ashish" << endl;
}

signed main() {
    // OJ();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    if (true)
        cin >> tt;
    while (tt--) lego();

    return 0;
}