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

    int cur_x = 0, cur_y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') cur_y++;
        if (s[i] == 'D') cur_y--;

        if (s[i] == 'R') cur_x++;
        if (s[i] == 'L') cur_x--;

        int x_block = cur_x;
        int y_block = cur_y;
        int new_x = 0, new_y = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'U') new_y++;
            if (s[j] == 'D') new_y--;

            if (s[j] == 'R') new_x++;
            if (s[j] == 'L') new_x--;

            if (new_x == x_block and new_y == y_block) {
                if (s[j] == 'U') new_y--;
                if (s[j] == 'D') new_y++;
                if (s[j] == 'R') new_x--;
                if (s[j] == 'L') new_x++;
            }
        }

        if (new_x == 0 and new_y == 0) {
            cout << x_block << " " << y_block << endl;
            return;
        }
    }

    cout << 0 << " 0" << endl;
    return;
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