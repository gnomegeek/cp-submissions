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

int n;
vector<int> tre[maxn];
vector<int> vis(maxn, 0);

int dp[maxn][2];

int dfs(int i, int isdone, int parent) {
    int res = 0;

    if (dp[i][isdone] != -1) return dp[i][isdone];

    if (isdone) {
        int cnt = 0;
        for (int j : tre[i]) {
            if (parent != j) {
                cnt += dfs(j, 0, i);
            }
        }

        return dp[i][isdone] = cnt;
    } else {
        int cnt = 0;

        vector<pii> v;

        for (int j : tre[i]) {
            if (parent != j) {
                v.pb({dfs(j, 0, i), j});
                cnt += v.back().F;
            }
        }

        int temp = 0;
        for (auto j : v) {
            int val = dfs(j.S, 1, i);
            temp = max(temp, val + 1 + cnt - j.F);
        }

        return dp[i][isdone] = temp;
    }
}
void letsGO(int test) {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tre[a].pb(b);
        tre[b].pb(a);
    }

    memset(dp, -1, sizeof dp);

    cout << dfs(1, 0, -1) << endl;
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