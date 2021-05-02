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

vector<int> vis1(maxn, 0), vis2(maxn, 0);
vector<int> gr1[maxn], gr2[maxn];
int vis1cnt = 0, vis2cnt = 0;

void dfs1(int i) {
    vis1[i] = 1;
    for (auto nbr : gr1[i])
        if (!vis1[nbr])
            dfs1(nbr);
}

void dfs2(int i) {
    vis2[i] = 1;
    for (auto nbr : gr2[i])
        if (!vis2[nbr])
            dfs2(nbr);
}

void letsGO(int test) {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        gr1[a].pb(b);
        gr2[b].pb(a);
    }

    dfs1(1);
    dfs2(1);

    for (int i = 1; i <= n; i++) {
        if (!vis1[i]) {
            cout << "NO\n1 " << i << endl;
            return;
        }

        if (!vis2[i]) {
            cout << "NO\n"
                 << i << " 1" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
