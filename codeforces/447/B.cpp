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
    int k, maxk = -inf;
    cin >> s;
    cin >> k;
    int asd[26];
    for (int i = 0; i < 26; i++) {
        cin >> asd[i];
        maxk = max(maxk, asd[i]);
    }

    int val = 0;
    for (int i = 0; i < s.length(); i++) {
        val += (asd[s[i] - 'a'] * (i + 1));
    }

    for (int i = s.length(); i < s.length() + k; i++) {
        val += maxk * (i + 1);
    }
    cout << val << endl;
    return;
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