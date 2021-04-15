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

void letsGO(int test) {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int> > graph(n + 1, vector<int>(n + 1, linf));

    for (int i = 0; i <= n; i++) graph[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (x == i || y == i || x == y) continue;
                graph[x][y] = min(graph[x][y], graph[x][i] + graph[i][y]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = (graph[i][j] == linf ? -1 : graph[i][j]);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << graph[a][b] << endl;
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