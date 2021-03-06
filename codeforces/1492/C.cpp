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

void lego() {
    int n, k, m, cnt = 0;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    int l[k], r[k];

    int i = 0, j = 0;
    while (j != k) {
        if (s[i] == t[j]) l[j++] = i + 1;
        i++;
    }
    j = k - 1;
    i = n - 1;
    while (j != -1) {
        if (s[i] == t[j]) r[j--] = i + 1;
        i--;
    }
    int best = -inf;
    for (int i = 0; i < k - 1; i++) best = max(best, r[i + 1] - l[i]);

    cout << best << endl;
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