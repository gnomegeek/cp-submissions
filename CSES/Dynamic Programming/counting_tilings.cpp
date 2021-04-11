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

int dp[2000][2000];

vector<vector<int> > nextmasks(1024, vector<int>());

void getMasks(int limit, int n) {
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            bool ok = true;
            vector<int> bits;
            for (int k = 0; k < n; k++) {
                int ibit = (i >> k) & 1;
                int jbit = (j >> k) & 1;
                if (ibit == 1 and jbit != 0) {
                    ok = false;
                    break;
                }

                if (ibit == 0 and jbit == 0)
                    bits.pb(n - k - 1);
            }

            if (!ok) continue;

            if (bits.size() % 2 != 0) continue;

            reverse(bits.begin(), bits.end());

            for (int k = 1; k < bits.size(); k += 2) {
                if (bits[k] - bits[k - 1] != 1) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            nextmasks[i].pb(j);
        }
    }
}

int getCnt(int last, int rem, int limit, int n) {
    if (rem == 0) {
        if (last == 0) return 1;
        return 0;
    }

    if (dp[last][rem] != -1) return dp[last][rem];

    int cnt = 0;

    for (int i : nextmasks[last])
        cnt = (cnt + getCnt(i, rem - 1, limit, n)) % mod;

    return dp[last][rem] = cnt;
}

void letsGO(int test) {
    int n, m;
    cin >> n >> m;

    int limit = 1 << n;

    memset(dp, -1, sizeof dp);
    getMasks(limit, n);

    int cnt = getCnt(0, m, limit, n) % mod;

    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(6);
    int TT = 1, cnt = 0;
    if (cases) cin >> TT;
    while (TT--) letsGO(++cnt);
}