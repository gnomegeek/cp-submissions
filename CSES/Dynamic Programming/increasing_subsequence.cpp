#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ump unordered_map
#define endl "\n"
#define null NULL
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
const int maxn = 200050;

void oj() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dp[maxn];

void lego() {
    int n, k, m, cnt = 0;
    cin >> n;
    vi a(n);
    enter(a);
    int temp = 1;
    memset(dp, -1, sizeof(dp));
    vi candidates;
    dp[0] = 1;
    candidates.pb(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] > candidates[cnt]) {
            candidates.pb(a[i]);
            dp[i] = candidates.size();
            cnt++;
        } else {
            auto itr = lower_bound(candidates.begin(), candidates.end(), a[i]);
            int idx = itr - candidates.begin();
            candidates[idx] = a[i];
            dp[i] = idx + 1;
        }
        temp = max(temp, dp[i]);
    }

    cout << temp << endl;
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