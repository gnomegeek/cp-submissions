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
const int maxn = 5004;

void oj() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dp[maxn][maxn];

int f(vi& b, int l, int r) {
    if (l >= r)
        return 0;
    else if (l == r - 1)
        return 1;

    if (dp[l][r] != -1) return dp[l][r];

    if (b[l] == b[r])
        return dp[l][r] = 1 + f(b, l + 1, r - 1);
    else
        return dp[l][r] = min(f(b, l + 1, r), f(b, l, r - 1)) + 1;
}

void lego() {
    int n, k, m, cnt = 0;
    cin >> n;
    vi a(n);
    enter(a);

    vi b;
    b.pb(a[0]);
    memset(dp, -1, sizeof dp);
    for (int i = 1; i < a.size(); i++)
        if (a[i] != a[i - 1]) b.pb(a[i]);

    cout << f(b, 0, b.size() - 1) << endl;
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