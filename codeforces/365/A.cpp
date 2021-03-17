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
    int n, k;
    cin >> n >> k;
    umap<int, bool> l;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (l.count(x)) {
            if (l[x]) cnt++;
        } else {
            int a[10] = {0};
            int xc = x;
            while (xc != 0) {
                int dig = xc % 10;
                a[dig]++;
                xc /= 10;
            }

            if (!l.count(x)) {
                for (int i = 0; i <= k; i++) {
                    if (a[i] == 0) {
                        l[x] = false;
                        i = k;
                    }
                }

                if (!l.count(x)) {
                    l[x] = true;
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
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