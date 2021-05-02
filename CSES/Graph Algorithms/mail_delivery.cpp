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

vector<int> deg(maxn, 0), vis(maxn, 0);
set<int, greater<int> > gr2[maxn];

void dfs(int i) {
    vis[i] = 1;
    for (auto nbr : gr2[i])
        if (!vis[nbr])
            dfs(nbr);
}

void letsGO(int test) {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        gr2[a].insert(b);
        gr2[b].insert(a);
        deg[a]++;
        deg[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (deg[i] > 0) {
                cout << "IMPOSSIBLE"
                     << endl;
                return;
            }
        }
    }

    stack<int> cur, res;

    cur.push(1);
    while (!cur.empty()) {
        int node = cur.top();
        if (gr2[node].size() == 0) {
            res.push(node);
            cur.pop();
            continue;
        }

        int nbr = *gr2[node].begin();

        cur.push(nbr);

        gr2[node].erase(gr2[node].begin());
        gr2[nbr].erase(gr2[nbr].find(node));
    }

    while (!res.empty()) cout << res.top() << " ", res.pop();
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