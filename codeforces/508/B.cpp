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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> evens;
    for (int i = 0; i < n; i++) {
        int dig = s[i] - '0';
        if (dig % 2 == 0)
            evens.push_back(i);
    }

    if (evens.size() == 0) {
        cout << "-1" << endl;
        return;
    }

    int last_dig = s[n - 1] - '0';

    for (int i : evens) {
        int dig = s[i] - '0';
        if (dig < last_dig) {
            swap(s[n - 1], s[i]);
            cout << s << endl;
            return;
        }
    }

    swap(s[n - 1], s[*(--evens.end())]);
    cout << s << endl;
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