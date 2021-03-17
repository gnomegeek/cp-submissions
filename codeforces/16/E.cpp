#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ump unordered_map
#define endl "\n"
#define pb push_back
#define all(x) x.begin(), x.end();
#define enter(a) \
    for (int i = 0; i < a.size(); i++) cin >> a[i];

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pii;
typedef unordered_map<int, int> upii;
typedef vector<vector<int>> vvi;

const int linf = 1e18;
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int maxn = (1 << 18);

void oj() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<vector<double>> prob(20, vector<double>(20));
double dp[maxn];

double get_prob(int mask, int n) {
    if (mask == (1 << n) - 1) return 1;

    if (dp[mask] > -1) return dp[mask];

    int alive = __builtin_popcount(mask);
    int dead = n - alive;
    int mc1 = mask, mc2 = mask;
    double res = 0;

    int i = 1;
    while (i != (n + 1)) {
        if (!(mc1 & 1)) {
            double p = 0;
            int j = 1;
            mc2 = mask;
            while (j != (n + 1)) {
                if (mc2 & 1) p += (prob[j][i]);
                j++;
                mc2 = mc2 >> 1;
            }
            int alive_prev_day = __builtin_popcount(mask | (1 << (i - 1)));
            double kc2 = alive_prev_day * (alive_prev_day - 1) / 2;
            res += p * get_prob(mask | (1 << (i - 1)), n) * (1 / kc2);
        }
        mc1 = mc1 >> 1;
        i++;
    }

    return dp[mask] = res;
}

void lego() {
    int n, k, m, cnt = 0;
    cin >> n;

    for (int i = 0; i < maxn; i++) dp[i] = -2;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> prob[i][j];

    vector<double> res(n + 1, 0);
    for (int i = 1; i <= n; i++) res[i] = get_prob(1 << (i - 1), n);

    for (int i = 1; i <= n; i++)
        cout << fixed << setprecision(6) << res[i] << " ";
    cout << endl;
}

signed main() {
    oj();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TT = 1;
    if (false) cin >> TT;
    while (TT--) lego();
}