#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define ump unordered_map
#define endl "\n"
#define mod 1000000007

void OJ() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
const int maxn = 100001;
// int a[maxn], n, x, y, k, b, c, sum;
// string s, str;
char ch;

void lego() {
    int x, y;
    string s;
    cin >> x >> y;
    cin >> s;
    int upper = 0, right = 0, left = 0, down = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'U') upper++;
        if (s[i] == 'R') right++;
        if (s[i] == 'D') down++;
        if (s[i] == 'L') left++;
    }

    if (x >= 0 and y >= 0) {
        if (upper >= y and right >= x) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if (x >= 0 and y <= 0) {
        if (down >= abs(y) and right >= x) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if (x <= 0 and y <= 0) {
        if (left >= abs(x) and down >= abs(y)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (left >= abs(x) and upper >= y) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return;
}

int main() {
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