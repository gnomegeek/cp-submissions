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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int maxn = 2e5 + 100;

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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int mod_div(int a, int b) { return a * fastexpo(b, mod - 2) % mod; }

bool cases = 0;

vector<int> dp(maxn, 0), vis(maxn, 0), coins(maxn, 0), topo, compInfo(maxn, 0), compCoins(maxn, 0);
vector<int> gr[maxn], gr2[maxn], gr3[maxn];
int cnt = 0;

void dfs(int i) {
    vis[i] = 1;
    for (int nbr : gr[i])
        if (!vis[nbr])
            dfs(nbr);

    topo.pb(i);
}

void dfs2(int i) {
    vis[i] = 1;
    for (auto nbr : gr2[i])
        if (!vis[nbr])
            dfs2(nbr);

    compInfo[i] = cnt;
    compCoins[cnt] += coins[i];
}

int dfs3(int i) {
    if (dp[i] != 0) return dp[i];

    vis[i] = 1;

    for (auto nbr : gr3[i])
        dp[i] = max(dp[i], dfs3(nbr));

    dp[i] += compCoins[i];

    return dp[i];
}

void letsGO(int test) {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> coins[i];

    vector<pii> edges;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        gr[a].pb(b);
        gr2[b].pb(a);
        edges.pb({a, b});
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);

    vis.assign(maxn, 0);
    reverse(all(topo));

    for (int i : topo)
        if (!vis[i])
            cnt++, dfs2(i);

    vector<pii> sccedges;

    for (auto edge : edges)
        if (compInfo[edge.F] != compInfo[edge.S])
            sccedges.pb({compInfo[edge.F], compInfo[edge.S]});

    for (auto edge : sccedges)
        gr3[edge.F].pb(edge.S);

    vis.assign(maxn, 0);

    int mx = 0;

    for (int i = 1; i <= cnt; i++) {
        if (!vis[i]) {
            dfs3(i);
        }
    }

    for (int i = 1; i <= cnt; i++)
        mx = max(mx, dp[i]);

    cout << mx << endl;
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