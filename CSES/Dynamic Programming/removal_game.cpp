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

int dp[5001][5001];

int score(vi& a, int start, int end) {
    if (start == end) return a[start];

    if (end - start == 1) return max(a[end], a[start]);

    if (dp[start][end] != -1) return dp[start][end];

    int op1 = score(a, start + 2, end) + a[start];      // set1
    int op2 = score(a, start + 1, end - 1) + a[start];  // set1
    int op3 = score(a, start + 1, end - 1) + a[end];    // set2
    int op4 = score(a, start, end - 2) + a[end];        // set2

    return dp[start][end] = max(min(op1, op2), min(op3, op4));
}

void lego() {
    int n, k, sum = 0, m, cnt = 0;
    cin >> n;
    vi a(n);
    enter(a);
    memset(dp, -1, sizeof dp);
    cout << score(a, 0, n - 1);
    // cout << mn << endl;
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