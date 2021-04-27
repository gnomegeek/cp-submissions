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

int n;
const int LOG = 19;
vector<int> parent(maxn, -1);

vector<int> depths(maxn, -1);

vector<int> tre[maxn];

int dp[maxn][LOG];

void updateDepths(int i, int par, int cur) {
    depths[i] = cur;
    for (auto j : tre[i]) {
        if (j != par)
            updateDepths(j, i, cur + 1);
    }
}

void letsGO(int test) {
    int q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
        tre[parent[i]].pb(i);
    }

    updateDepths(1, -1, 0);

    memset(dp, -1, sizeof dp);

    for (int i = 1; i <= n; i++) dp[i][0] = parent[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 1; j <= n; j++)
            dp[j][i] = dp[j][i - 1] == -1 ? -1 : dp[dp[j][i - 1]][i - 1];

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (depths[a] < depths[b])
            swap(a, b);

        int k = depths[a] - depths[b];

        for (int i = 0; i < LOG; i++) {
            if ((k >> i) & 1)
                a = dp[a][i];
        }

        if (a == b) {
            cout << a << " ";
            continue;
        }

        for (int i = LOG - 1; i >= 0; i--) {
            if (dp[a][i] != dp[b][i] and dp[a][i] != -1 and dp[b][i] != -1) {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        cout << dp[a][0] << " ";
    }

    cout << endl;
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