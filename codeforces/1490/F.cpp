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
    int n, x, sum = 0;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (cnt.count(x))
            cnt[x]++;
        else
            cnt[x] = 1;
    }

    vi a(cnt.size());
    int j = 0;
    for (auto i : cnt) {
        a[j++] = i.second;
        sum += i.second;
    }

    sort(all(a), greater<int>());
    int res = inf;
    for (int i = 0; i < a.size(); i++) {
        int thrown = sum - ((i + 1) * a[i]);
        res = min(thrown, res);
    }

    cout << res << endl;
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