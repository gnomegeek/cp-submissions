#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, h[5010], k;
inline int solve(int n, int k) {
    int no = 0;
    while (no != k) {
        no++;
        int f = 0;
        for (int i = 1; i < n; ++i) {
            if (h[i] < h[i + 1]) {
                h[i]++, f = 1;
                if (no == k)
                    return i;
                else
                    break;
            }
        }
        if (f == 0) return -1;
    }
    return -1;
}
void re() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> h[i];
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        re();
        cout << solve(n, k) << '\n';
    }
    return 0;
}