#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ump unordered_map
#define endl "\n"
#define pb push_back
#define all(x) x.begin(), x.end();
#define enter(a) \
    for (int i = 0; i < a.size(); i++) cin >> a[i];

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pii;
typedef unordered_map<int, int> upii;
typedef vector<vector<int>> vvi;

const int linf = 1e18;
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int maxn = 1 << 15;

void oj() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vvi dp1(maxn, vi(16));
vvi dp2(maxn, vi(16));

pair<int, int> perimeter(vi &a, int mask, int lastidx) {
    int n = a.size();
    if (mask == (1 << n) - 1) return {0, 1};
    if (dp1[mask][lastidx] != -1 and dp2[mask][lastidx] != -1)
        return {dp1[mask][lastidx], dp2[mask][lastidx]};
    int j = 1;
    int cnt = 0;
    int res_max = 0;
    while (j != n + 1) {
        if (!(mask & (1 << (j - 1)))) {
            int extra = 2 + abs(a[lastidx] - a[j - 1]) + a[j - 1] - a[lastidx];
            pii subproblem_pair = perimeter(a, mask ^ (1 << (j - 1)), j - 1);
            int val = subproblem_pair.first + extra;

            if (val > res_max) {
                cnt = subproblem_pair.second;
                res_max = val;
            } else if (val == res_max)
                cnt += (subproblem_pair.second);
        }
        j++;
    }
    dp1[mask][lastidx] = res_max;
    dp2[mask][lastidx] = cnt;
    return {res_max, cnt};
}

signed main() {
    oj();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true) {
        int n;
        cin >> n;
        if (n != 0) {
            vi a(n);
            enter(a);

            for (int i = 0; i < maxn; i++) {
                for (int j = 0; j < 16; j++) {
                    dp1[i][j] = -1;
                    dp2[i][j] = -1;
                }
            }

            int res_max = -inf, cnt = 0;
            for (int i = 1; i <= n; i++) {
                pii subproblem_pair = perimeter(a, (1 << (i - 1)), i - 1);

                int val = subproblem_pair.first + 2 * (a[i - 1]) + 2;

                if (val > res_max) {
                    cnt = subproblem_pair.second;
                    res_max = val;
                } else {
                    if (val == res_max) cnt += subproblem_pair.second;
                }
            }
            cout << res_max << " " << cnt << endl;
        } else
            return 0;
    }
}