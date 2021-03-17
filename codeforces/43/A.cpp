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
#define umap unordered_map
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

void lego() {
    int n;
    cin >> n;
    umap<string, int> l;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (l.count(s)) {
            l[s]++;
        } else {
            l[s] = 1;
        }
    }

    string res;
    int goals = INT_MIN;
    for (auto i : l) {
        if (i.second > goals) {
            res = i.first;
            goals = i.second;
        }
    }

    cout << res << endl;
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