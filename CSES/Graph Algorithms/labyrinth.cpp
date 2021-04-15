
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
string s = "RLDU";

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
pii parent[1002][1002];
int vis[1002][1002];
int r, c;
map<pii, char> mp;

bool possible(int i, int j) {
    return !(i < 1 || i > r || j < 1 || j > c);
}

void letsGO(int test) {
    cin >> r >> c;

    mp[{0, 1}] = 'R';
    mp[{0, -1}] = 'L';
    mp[{1, 0}] = 'D';
    mp[{-1, 0}] = 'U';

    pair<int, int> g, f;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> mat[i][j];
            parent[i][j] = {-1, -1};
            if (mat[i][j] == 'A') g = {i, j};
            if (mat[i][j] == 'B') f = {i, j};
        }
    }

    queue<pii> Q;

    Q.push(g);

    memset(vis, 0, sizeof vis);

    bool found = false;

    vis[g.F][g.S] = 1;

    while (!Q.empty()) {
        int sz = Q.size();

        for (int i = 0; i < sz; i++) {
            pii cur = Q.front();
            Q.pop();
            int x = cur.F, y = cur.S;

            for (int k = 0; k < 4; k++) {
                if (possible(x + dx[k], y + dy[k]) and mat[x + dx[k]][y + dy[k]] != '#' and !vis[x + dx[k]][y + dy[k]]) {
                    vis[x + dx[k]][y + dy[k]] = 1;

                    Q.push({x + dx[k], y + dy[k]});

                    parent[x + dx[k]][y + dy[k]] = cur;

                    if (mat[x + dx[k]][y + dy[k]] == 'B') {
                        found = true;
                        while (!Q.empty()) Q.pop();
                        i = inf;
                        break;
                    }
                }
            }
        }
    }

    if (!found) {
        cout << noo;
        return;
    }

    cout << yess << endl;

    vector<pii> path;

    pii cur = f;

    while (mat[cur.F][cur.S] != 'A') {
        path.pb(cur);
        cur = parent[cur.F][cur.S];
    }

    path.pb(g);

    reverse(all(path));

    cout << path.size() - 1 << endl;

    for (int i = 0; i < path.size() - 1; i++) {
        pii jj = {path[i + 1].F - path[i].F, path[i + 1].S - path[i].S};
        cout << mp[jj];
    }
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