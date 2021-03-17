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
    int turn = 1;
    for (int i = 0; i < n; i++) {
        if (turn) {
            if (s[i] == 'a') {
                cout << 'b';
            } else {
                cout << 'a';
            }
        } else {
            if (s[i] == 'z') {
                cout << 'y';
            } else {
                cout << 'z';
            }
        }
        turn = !turn;
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