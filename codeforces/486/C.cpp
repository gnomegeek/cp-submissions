/*
    Author: Vatsal Agarwal
    Birla Institute of Technology and Sciences, Pilani, Goa Campus

    Make it work, make it right, make it fast.
*/

#include <bits/stdc++.h>
using namespace std;
typedef int itn;
#define int long long
#define inf INT_MAX
#define umap unordered_map<int, int>
#define endl "\n"
#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define mid(s, e) ((s + (e - s) / 2))
#define mod 1000000007
#define scArray(a, b) \
    for (int i = 0; i < b; i++) cin >> a[i]
void OJ() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// assign 1 to tt for testcases
int TT = 0;

int dif(char c1, char c2) {
    if (c1 == c2) return 0;
    char small = min((int)c1, (int)c2);
    char big = max((int)c1, (int)c2);

    int op1 = big - small;
    int op2 = small - 'a' + 26 - (big - 'a');

    return min(op1, op2);
}

int minSteps(string s, int n, int m) {
    if (n % 2 == 0) {
        if (m >= n / 2)
            m = n - m - 1;
    } else {
        if (m > n / 2)
            m = n - m - 1;
    }
    vector<int> v;
    int res = 0;
    int done = 0, cnt = 0, midx;
    for (int i = 0; i < n / 2 + (n % 2); i++) {
        if (i == m and !done) {
            midx = cnt;
            v.push_back(m);
            cnt++;
            done = 1;
        }
        if (s[i] != s[n - 1 - i]) {
            res += (dif(s[i], s[n - i - 1]));
            if (i > m and !done) {
                midx = cnt;
                v.push_back(m);
                cnt++;
                done = 1;
            }
            v.push_back(i);
            cnt++;
        }
    }
    if (n & 1 and m == n / 2 + 1) {
        v.push_back(m);
        midx = cnt;
    }

    // for (auto i : v) cout << i << endl;

    int left = 0, right = 0;

    if (v.size() == 1)
        return 0;

    right = v[v.size() - 1] - m;
    left = m - v[0];

    // cout << left << " " << right << endl;

    int small = min(left, right);
    int big = max(left, right);

    res += 2 * small + big;

    return res;
}

void lego() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    cout << minSteps(s, n, m - 1);
}

signed main() {
    OJ();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (TT) {
        cin >> TT;
        while (TT--) {
            lego();
        }
    } else
        lego();
}