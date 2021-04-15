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

bool possible(int i, int j, int r, int c) {
    return !(i < 1 || i > r || j < 1 || j > c);
}

bool isBoundary(int i, int j, int r, int c) {
    return (i == 1 || i == r || j == 1 || j == c);
}

void letsGO(int test) {
    int r, c;
    cin >> r >> c;
    char mat[r + 1][c + 1];
    map<pii, char> mp;

    mp[{0, 1}] = 'R';
    mp[{0, -1}] = 'L';
    mp[{1, 0}] = 'D';
    mp[{-1, 0}] = 'U';

    vector<vector<int> > mndis(r + 1, vector<int>(c + 1, inf));

    queue<pii> Q;
    pii start;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> mat[i][j];

            if (mat[i][j] == 'A') start = {i, j};
            if (mat[i][j] == 'M') Q.push({i, j}), mndis[i][j] = 0;
        }
    }

    int d = 1;
    while (!Q.empty()) {
        int sz = Q.size();
        for (int i = 0; i < sz; i++) {
            pii cur = Q.front();
            Q.pop();
            for (int k = 0; k < 4; k++) {
                int x = cur.F + dx[k], y = cur.S + dy[k];
                if (possible(x, y, r, c) and mndis[x][y] == inf and mat[x][y] != '#') {
                    mndis[x][y] = d;
                    Q.push({x, y});
                }
            }
        }
        d++;
    }

    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            if (mat[i][j] == '#') mndis[i][j] = 0;
        }
    }

    Q.push(start);

    vector<vector<int> > vis(r + 1, vector<int>(c + 1, 0));
    vis[start.F][start.S] = 1;
    d = 1;

    vector<vector<pii> > parent(r + 1, vector<pii>(c + 1, {-1, -1}));

    while (!Q.empty()) {
        int sz = Q.size();

        for (int i = 0; i < sz; i++) {
            pii cur = Q.front();
            Q.pop();

            if (isBoundary(cur.F, cur.S, r, c)) {
                pii curr = {cur.F, cur.S};

                cout << yess << endl;

                vector<pii> paths;
                while (curr != start) {
                    paths.pb(curr);
                    curr = parent[curr.F][curr.S];
                }
                paths.pb(start);
                cout << paths.size() - 1 << endl;
                reverse(all(paths));
                vector<char> res;
                for (int a = 0; a < paths.size() - 1; a++)
                    res.pb(mp[{paths[a + 1].F - paths[a].F, paths[a + 1].S - paths[a].S}]);

                for (char ch : res) cout << ch;

                return;
            }

            for (int k = 0; k < 4; k++) {
                int x = cur.F + dx[k], y = cur.S + dy[k];
                if (possible(x, y, r, c) and mndis[x][y] > d and !vis[x][y]) {
                    vis[x][y] = 1;
                    Q.push({x, y});
                    parent[x][y] = cur;
                }
            }
        }

        d++;
    }

    cout << noo << endl;
    return;
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