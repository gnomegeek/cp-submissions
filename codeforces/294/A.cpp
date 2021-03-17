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

// assign 1 to tt for testcases
int TT = 0;

void lego() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    while (m--) {
        int wire, bird;
        cin >> wire >> bird;

        int left = wire == 1 ? 0 : bird - 1;
        int right = wire == n ? 0 : a[wire] - bird;
        a[wire] = 0;
        if (wire == 1)
            a[wire + 1] += right;
        else if (wire == n)
            a[wire - 1] += left;
        else {
            a[wire + 1] += right;
            a[wire - 1] += left;
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << endl;
}

signed main() {
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