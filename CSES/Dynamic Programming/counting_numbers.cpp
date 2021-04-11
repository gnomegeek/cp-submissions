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

int dp[20][2][11][2];

int f(string a, int i, bool tight, int last, bool started) {
    if (i == a.length()) return 1;

    if (dp[i][tight][last][started] != -1) return dp[i][tight][last][started];

    int cnt = 0;

    for (int j = 0; j < 10; j++) {
        if (started and j == last) continue;

        if (tight) {
            if (j > a[i] - '0') break;
            cnt += f(a, i + 1, j == a[i] - '0', j, started || j > 0);
        } else {
            cnt += f(a, i + 1, 0, j, started || j > 0);
        }
    }

    return dp[i][tight][last][started] = cnt;
}

void letsGO(int test) {
    int a, b;

    cin >> a >> b;

    string str1 = to_string(a - 1), str2 = to_string(b);

    memset(dp, -1, sizeof dp);
    int g1 = f(str2, 0, 1, 10, 0);

    if (b == 0) {
        cout << 1 << endl;
        return;
    }

    if (a == 0) {
        cout << g1 << endl;
        return;
    }

    if (a == 1) {
        cout << g1 - 1 << endl;
        return;
    }

    memset(dp, -1, sizeof dp);
    int g2 = f(str1, 0, 1, 10, 0);

    cout << g1 - g2 << endl;
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