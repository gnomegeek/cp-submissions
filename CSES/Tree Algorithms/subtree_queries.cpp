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

struct node {
   public:
    int num, val;

    node(int x, int v) {
        num = x;
        val = v;
    }
};

int st[maxn] = {0}, ed[maxn] = {0};
int n;
vector<int> nt[maxn];
vector<int> tre(8e5 + 1);
map<int, int> vals;
int timer = 1;
vector<int> flatt;
vector<int> idxes;

void dfs(int i, int par) {
    st[i] = timer++;
    flatt.pb(i);
    for (auto j : nt[i]) {
        if (j != par) {
            dfs(j, i);
        }
    }
    ed[i] = timer - 1;
}

void update(vector<int> &tre, int k, int lx, int rx, int i, int val) {
    if (lx == rx) {
        tre[k] = val;
        return;
    }

    int m = (lx + rx) / 2;

    if (i <= m)
        update(tre, 2 * k, lx, m, i, val);
    else
        update(tre, 2 * k + 1, m + 1, rx, i, val);

    tre[k] = tre[2 * k] + tre[2 * k + 1];
}
int query(vector<int> &tre, int k, int lx, int rx, int l, int r) {
    if (l > rx || r < lx) return 0;

    if (l <= lx and r >= rx) return tre[k];
    int m = (lx + rx) / 2;
    int one = query(tre, 2 * k, lx, m, l, r);
    int two = query(tre, 2 * k + 1, m + 1, rx, l, r);

    return one + two;
}

void letsGO(int test) {
    int q;
    cin >> n >> q;

    flatt.pb(0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vals[i] = x;
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        nt[a].pb(b);
        nt[b].pb(a);
    }

    dfs(1, -1);

    idxes.resize(maxn);

    for (int i = 1; i <= n; i++)
        idxes[flatt[i]] = i;

    for (int i = 1; i <= n; i++)
        update(tre, 1, 1, n, i, vals[flatt[i]]);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;

            update(tre, 1, 1, n, idxes[s], x);

        } else {
            int s;
            cin >> s;

            cout << query(tre, 1, 1, n, st[s], ed[s]) << endl;
        }
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