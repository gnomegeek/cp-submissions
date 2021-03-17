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
const int maxn = 200050;

void oj() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dp[maxn];

int projects(vvi& info, int i) {
    int n = info.size();
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];
    int op1 = projects(info, i + 1);
    int op2, start = i + 1, end = n - 1, search = info[i][1], ans = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (info[mid][0] > search) {
            ans = mid;
            end = mid - 1;
        } else
            start = mid + 1;
    }

    if (ans == -1)
        op2 = info[i][2];
    else
        op2 = projects(info, ans) + info[i][2];
    return dp[i] = max(op1, op2);
}

void lego() {
    int n, k, m, cnt = 0;
    cin >> n;
    vvi info(n, vector<int>(3));
    for (int i = 0; i < n; i++) cin >> info[i][0] >> info[i][1] >> info[i][2];
    memset(dp, -1, sizeof dp);
    sort(info.begin(), info.end());

    cout << projects(info, 0) << endl;
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