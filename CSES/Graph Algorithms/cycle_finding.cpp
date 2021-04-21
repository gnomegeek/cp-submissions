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

void letsGO(int test) {
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1, -1);

    vector<int> edges[m];

    vector<int> dis(n + 1, INF);

    dis[1] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 0; j < m; j++) {
            int u = edges[j][0], v = edges[j][1], wt = edges[j][2];
            // if (dis[u] < INF) {
            if (dis[u] + wt < dis[v]) {
                dis[v] = max(-INF, dis[u] + wt);
                parent[v] = u;
                x = v;
                // }
            }
        }
    }

    if (x == -1) {
        cout << noo << endl;
        return;
    }

    for (int i = 0; i < n; i++)
        x = parent[x];

    int cur = x;

    vector<int> path;
    while (cur != x || path.size() <= 1) {
        path.pb(cur);
        cur = parent[cur];
    }

    path.pb(cur);

    reverse(all(path));

    cout << yess << endl;

    for (auto i : path) cout << i << " ";
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
