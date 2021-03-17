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
    int n, k, m;
    cin >> n;
    vi a(n);
    enter(a);

    if (n == 1) {
        cout << a[0] << endl;
        return;
    }

    int leftmax[n];
    int global_max_idx = 0;
    leftmax[0] = 0;
    leftmax[1] = 0;
    if (a[1] > a[global_max_idx]) global_max_idx = 1;
    for (int i = 2; i < n; i++) {
        if (a[i] > a[global_max_idx]) {
            global_max_idx = i;
        }
        if (a[leftmax[i - 1]] < a[i - 1]) {
            leftmax[i] = i - 1;
        } else {
            leftmax[i] = leftmax[i - 1];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << leftmax[i] << " ";
    // }
    // cout << endl;

    int cnt = global_max_idx;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--) {
        while (i != cnt) {
            res.pb(a[i]);
            i--;
        }
        if (i == cnt) {
            cout << a[i] << " ";
            for (auto j = --res.end(); j != --res.begin(); j--) cout << *j << " ";
            res.clear();
            cnt = leftmax[i];
        }
    }
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