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

int cnt = 0;

void dijkstra(vector<vector<pair<int, int>>>& graph, int n, int src, vector<int>& dis) {
    set<pair<int, int>> q;
    dis.resize(n + 1, INF);
    dis[src] = 0;
    int mx = -1;
    q.insert({0, src});
    vector<int> vis(n + 1, 0);

    // cout << q.size() << " gg " << q.begin()->F << " " << q.begin()->S << endl;
    while (!q.empty()) {
        pair<int, int> cur = *q.begin();
        q.erase(q.begin());
        for (auto j : graph[cur.S]) {
            if (dis[j.F] > dis[cur.S] + j.S) {
                auto itr = q.find({dis[j.F], j.F});
                if (itr != q.end()) q.erase(itr);
                dis[j.F] = dis[cur.S] + j.S;
                // mx = max(j.F, mx);
                q.insert({dis[j.F], j.F});
            }
        }
    }
}

void letsGO(int test) {
    int n, m;
    cin >> n >> m;
    // cout << n << endl;
    vector<vector<pii>> graph1(n + 1);
    vector<vector<int>> edges;
    vector<vector<pii>> graph2(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.pb({a, b, c});
        graph1[a].pb({b, c});
        graph2[b].pb({a, c});
    }

    // for (int i = n; i >= n - 20; i--) {
    //     cout << i << " -> ";
    //     for (auto j : graph2[i]) {
    //         cout << j.F << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> dis1, dis2;

    dijkstra(graph1, n, 1, dis1);

    dijkstra(graph2, n, n, dis2);

    int mn = INF;

    for (auto edge : edges) {
        mn = min(mn, dis1[edge[0]] + dis2[edge[1]] + edge[2] / 2);
    }

    cout << mn << endl;
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