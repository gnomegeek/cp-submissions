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

vector<pii> graph[100002];
vector<int> parent[100002];
vector<int> toposort;

int dp[100002];

int dfs(int i) {
    if (i == 1) return 1;

    if (dp[i] != -1) return dp[i];

    int res = 0;
    for (int j : parent[i]) {
        res = (res + dfs(j) % mod) % mod;
    }

    return dp[i] = res % mod;
}

void dfs2(int i, int vis2[]) {
    vis2[i] = true;

    for (int j : parent[i]) {
        if (!vis2[j]) {
            dfs2(j, vis2);
        }
    }

    toposort.pb(i);
}

int calc_max_dis(int src) {
    int vis3[src + 1] = {0};

    vector<int> dis(src + 1, 1);

    dis[src] = 0;

    for (int i : toposort) {
        for (auto j : parent[i]) {
            if (dis[j] > dis[i] - 1) {
                dis[j] = dis[i] - 1;
            }
        }
    }

    return dis[1] * (-1);
}

int calc_min_dis(int src) {
    vector<int> dis(src + 1, INF);

    dis[src] = 0;

    for (int i : toposort) {
        for (auto j : parent[i]) {
            if (dis[j] > dis[i] + 1) {
                dis[j] = dis[i] + 1;
            }
        }
    }

    return dis[1];
}

void letsGO(int test) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].pb({b, c});
    }

    vector<int> vis(n + 1, 0);
    vector<int> dis(n + 1, INF);

    set<pii> s;
    dis[1] = 0;
    s.insert({0, 1});
    while (!s.empty()) {
        int cur = (*(s.begin())).S;
        s.erase(s.begin());
        vis[cur] = 1;
        for (auto nbr : graph[cur]) {
            if (!vis[nbr.F]) {
                if (dis[nbr.F] > dis[cur] + nbr.S) {
                    auto itr = s.find({dis[nbr.F], nbr.F});
                    if (itr != s.end()) s.erase(itr);
                    dis[nbr.F] = dis[cur] + nbr.S;
                    s.insert({dis[nbr.F], nbr.F});
                    parent[nbr.F].clear();
                    parent[nbr.F].pb(cur);
                } else if (dis[nbr.F] == dis[cur] + nbr.S) {
                    parent[nbr.F].pb(cur);
                }
            }
        }
    }

    int cnt;

    int vis2[n + 1] = {0};

    memset(dp, -1, sizeof dp);

    cnt = dfs(n);

    cout << dis[n] << " ";

    int vis1[n + 1] = {0};

    cout << cnt << " ";

    dfs2(n, vis1);

    reverse(all(toposort));

    // for (int i : toposort) cout << i << " ";
    // cout << endl;

    cout << calc_min_dis(n) << " " << calc_max_dis(n);
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