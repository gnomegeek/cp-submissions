#include <bits/stdc++.h>
using namespace std;
typedef int itn;
#define int long long
#define inf INT_MAX
#define umap unordered_map<int, int>
#define endl "\n"
#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define mid(s, e) ((s + (e - s) / 2))
#define mod 1000000007
#define scArray(a, b) \
    for (int i = 0; i < b; i++) cin >> a[i]

// assign 1 to tt for testcases
int TT = 0;

int dp[100001][101];

int ways(int a[], int n, int i, int x, int m) {
    if (x < 1 || x > m) return 0;

    if (i == 0) {
        if (a[i] == 0) {
            return 1;
        } else {
            if (a[i] == x) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    if (dp[i][x] != -1) return dp[i][x];

    if (a[i] != 0) {
        if (a[i] == x)
            return dp[i][x] = ways(a, n, i - 1, a[i], m) % mod +
                              ways(a, n, i - 1, a[i] + 1, m) % mod +
                              ways(a, n, i - 1, a[i] - 1, m) % mod;
        else
            return dp[i][x] = 0;
    }

    return dp[i][x] = ways(a, n, i - 1, x, m) % mod +
                      ways(a, n, i - 1, x + 1, m) % mod +
                      ways(a, n, i - 1, x - 1, m) % mod;
}

void lego() {
    int n, m;
    cin >> n >> m;
    int a[n];
    scArray(a, n);
    int j = n - 1;

    if (n == 1) {
        if (a[0] == 0) {
            cout << m << endl;
        } else {
            cout << 1 << endl;
        }
        return;
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) dp[i][j] = -1;

    while (a[j] != 0) {
        j--;
        if (j == -1) {
            for (int i = 0; i < n - 1; i++) {
                if (abs(a[i] - a[i + 1]) > 1) {
                    cout << 0 << endl;
                    return;
                }
            }
            cout << 1 << endl;
            return;
        }
    }
    int res = 0;
    if (j == n - 1) {
        for (int i = 1; i <= m; i++) {
            res += ways(a, n, n - 1, i, m) % mod;
        }
    } else {
        int k = a[j + 1];
        res += (ways(a, n, j, k + 1, m) % mod + ways(a, n, j, k, m) % mod +
                ways(a, n, j, k - 1, m) % mod) %
               mod;
    }

    cout << res % mod << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (TT) {
        cin >> TT;
        while (TT--) {
            lego();
        }
    } else
        lego();
}