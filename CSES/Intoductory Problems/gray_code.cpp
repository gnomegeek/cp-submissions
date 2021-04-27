/* 
    Common Techniques:
    - Two Pointers
    - Binary Search
    - DP
    - Graph
    - Bitmasking
    - Divide and Conquer
    - Recursion

    Think Think Think !!!!
*/

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    wowset;

const int INF = 1e18;
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int modd = 998244353;
const string yess = "YES";
const string noo = "NO";
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int maxn = 2e5 + 100;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int fastexpo(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base);
        exp = exp >> 1;
        base = (base * base);
    }
    return res;
}

int mod_div(int a, int b) { return a * fastexpo(b, mod - 2) % mod; }

bool cases = 0;

vector<vector<int> > createStrings(int n) {
    if (n == 1) {
        return {{0}, {1}};
    }
    vector<vector<int> > x = createStrings(n - 1);

    vector<vector<int> > res;

    int lm = 1 << n;
    for (int i = 0; i < lm / 2; i++) {
        res.pb({0});
    }

    for (int i = 0; i < lm / 2; i++) {
        res.pb({1});
    }

    for (int i = 0; i < lm / 2; i++) {
        for (auto j : x[i]) {
            res[i].pb(j);
        }
    }

    int cnt = x.size() - 1;

    for (int i = lm / 2; i < lm; i++) {
        for (auto j : x[cnt]) {
            res[i].pb(j);
        }
        cnt--;
    }

    return res;
}

void letsGO(int test) {
    int n;
    cin >> n;

    vector<vector<int> > res = createStrings(n);

    for (auto j : res) {
        for (auto i : j) {
            cout << i;
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(6);
    int TT = 1, cnt = 0;
    if (cases) cin >> TT;
    while (TT--) letsGO(++cnt);
}