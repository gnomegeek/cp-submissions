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

int distance(string& s1, string& s2, int i, int j) {
    if (i == s1.length()) return s2.length() - j;
    if (j == s2.length()) return s1.length() - i;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) return dp[i][j] = distance(s1, s2, i + 1, j + 1);

    int replace = distance(s1, s2, i + 1, j + 1);
    int insert = distance(s1, s2, i, j + 1);
    int remove = distance(s1, s2, i + 1, j);

    return dp[i][j] = 1 + min(replace, min(insert, remove));
}

void lego() {
    int n, k, m, cnt = 0;
    string s1, s2;
    cin >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    cout << distance(s1, s2, 0, 0) << endl;
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