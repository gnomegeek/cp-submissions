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
    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vector<int> teams(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!teams[i]) {
            int team = 1;

            queue<int> Q;

            Q.push(i);
            teams[i] = 1;

            while (!Q.empty()) {
                int sz = Q.size();

                if (team == 1)
                    team = 2;
                else
                    team = 1;

                for (int z = 0; z < sz; z++) {
                    int node = Q.front();
                    Q.pop();

                    for (int nbr : graph[node]) {
                        if (teams[nbr] != 0) {
                            if (teams[nbr] != team) {
                                cout << "IMPOSSIBLE" << endl;
                                return;
                            }
                        } else {
                            teams[nbr] = team;
                            Q.push(nbr);
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << teams[i] << " ";
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