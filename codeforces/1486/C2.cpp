#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ump unordered_map
#define endl "\n"
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pb push_back

void oj() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int query(int a, int b) {
    if (a == b) return -1;
    cout << "? " << a << " " << b << endl << flush;
    int x;
    cin >> x;
    return x;
}

void lego() {
    int n;
    cin >> n;

    int lo, hi;

    int smx = query(1, n);

    if (smx == 1) {
        lo = 2;
        hi = n;
    } else if (smx == n) {
        lo = 1;
        hi = n - 1;
    } else {
        int k = query(1, smx);
        if (k == smx) {
            lo = 1;
            hi = smx - 1;
        } else {
            lo = smx + 1;
            hi = n;
        }
    }
    int ans;
    if (smx < lo) {
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (query(smx, mid) == smx) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << "! " << ans << endl;
    } else {
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (query(mid, smx) == smx) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << "! " << ans << endl;
    }
}

signed main() {
    oj();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TT = 1;
    if (false) cin >> TT;
    while (TT--) lego();
}