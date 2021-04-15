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

const int maxn = 2e5 + 100;
const int linf = 1000000000000000000LL;
const int mod = 1000000007LL;
const int inf = INT_MAX;
const int modd = 998244353;
const string yess = "YES";
const string noo = "NO";
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

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

int n, m;
vector<vector<pii> > graph;
vector<int> vis;
vector<int> dis;
multiset<pii> xx;

void dijkstra() {
    while (!xx.empty()) {
        pii cur = *xx.begin();

        xx.erase(xx.begin());

        vis[cur.S] = 1;

        for (auto nbr : graph[cur.S]) {
            if (!vis[nbr.F]) {
                auto itr = xx.find({dis[nbr.F], nbr.F});

                dis[nbr.F] = min(dis[nbr.F], cur.F + nbr.S);

                xx.erase(itr);

                xx.insert({dis[nbr.F], nbr.F});
            }
        }
    }
}

void letsGO(int test) {
    cin >> n >> m;

    graph.resize(n + 1, vector<pii>());

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].pb({b, c});
    }

    vis.resize(n + 1, 0);
    dis.resize(n + 1);

    for (int i = 0; i <= n; i++) dis[i] = linf;

    dis[1] = 0;

    for (int i = 1; i <= n; i++) xx.insert({dis[i], i});

    dijkstra();

    for (int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << endl;
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