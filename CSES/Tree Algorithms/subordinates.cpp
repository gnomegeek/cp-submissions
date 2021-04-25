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

const int linf = 1000000000000000000LL;
const int mod = 1000000007LL;
const int inf = INT_MAX;
const int modd = 998244353;
const string yess = "YES";
const string noo = "NO";

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

int mod_sub(int a, int b) { return ((a - b) % mod + mod) % mod; }

bool cases = 0;

int dp[200050];

int subs(int src, vector<vector<int> >& graph) {
    if (dp[src] != -1) return dp[src];

    int cnt = graph[src].size();
    for (int i : graph[src])
        cnt += subs(i, graph);

    return dp[src] = cnt;
}

void letsGO(int test) {
    int n;
    cin >> n;
    int a[n + 1] = {0};
    vector<vector<int> > graph(n + 1, vector<int>());

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        graph[x].pb(i);
    }

    memset(dp, -1, sizeof dp);

    for (int i = 1; i <= n; i++)
        a[i] = subs(i, graph);

    for (int i = 1; i <= n; i++) cout << a[i] << " ";
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