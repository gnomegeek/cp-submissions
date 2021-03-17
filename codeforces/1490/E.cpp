#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ump unordered_map
#define endl "\n"
#define pb push_back
#define all(x) x.begin(), x.end()
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
    cin >> n;
    vpi a(n);
    int maxidx = -1;
    for (int i = 0; i < n; i++) {
        cin >> k;
        a[i] = {k, i + 1};
    }
    sort(a.begin(), a.end());
    int sum[n];
    sum[0] = a[0].first;
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i].first;
    vi p;
    p.pb(a[n - 1].second);
    for (int i = n - 2; i >= 0; i--) {
        if (sum[i] >= a[i + 1].first) {
            p.pb(a[i].second);
        } else
            break;
    }
    int j = p.size() - 1;
    cout << p.size() << endl;
    sort(p.rbegin(), p.rend());
    while (j != -1) cout << p[j--] << " ";
    cout << endl;
}

signed main() {
    oj();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TT = 1;
    if (true) cin >> TT;
    while (TT--) lego();
}