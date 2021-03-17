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

set<int> res;

void money(vi& a, int i) {
    if (i == a.size()) return;
    vi temp;
    temp.pb(a[i]);
    for (auto j : res) temp.pb(j + a[i]);
    for (auto j : temp) res.insert(j);
    money(a, i + 1);
}

void lego() {
    int n, k, m, cnt = 0;
    cin >> n;
    vi a(n);
    enter(a);
    res.insert(a[0]);
    money(a, 1);
    cout << res.size() << endl;
    for (auto i : res) cout << i << " ";
    cout << endl;
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