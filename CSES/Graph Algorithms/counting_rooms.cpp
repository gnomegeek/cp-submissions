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

char mat[1002][1002];
int vis[1002][1002];
int r, c;

void dfs(int i, int j) {
    if (i <= 0 || i > r || j <= 0 || j > c) return;

    vis[i][j] = 1;

    if (mat[i][j] != '.') return;

    for (int k = 0; k < 4; k++)
        if (!vis[i + dx[k]][j + dy[k]])
            dfs(i + dx[k], j + dy[k]);
}

void letsGO(int test) {
    cin >> r >> c;

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> mat[i][j];

    memset(vis, 0, sizeof vis);

    int cnt = 0;

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (!vis[i][j] and mat[i][j] == '.') cnt++, dfs(i, j);

    cout << cnt << endl;
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
