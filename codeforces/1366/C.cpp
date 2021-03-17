#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define int long long
#define ump unordered_map
#define endl "\n"
#define mod 1000000007

void OJ() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void lego() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int zeros[m + n - 1];
    int ones[m + n - 1];
    int cnt = 0, res = 0;
    int row, col;
    for (int i = 0; i < m; i++) {
        row = 0;
        col = i;
        int z = 0, o = 0;
        while (row != n and col != -1) {
            if (a[row][col] == 0)
                z++;
            else
                o++;

            row++;
            col--;
        }
        zeros[cnt] = z;
        ones[cnt] = o;
        cnt++;
    }

    for (int i = 1; i < n; i++) {
        row = i;
        col = m - 1;
        int z = 0, o = 0;
        while (row != n and col != -1) {
            if (a[row][col] == 0)
                z++;
            else
                o++;

            row++;
            col--;
        }
        zeros[cnt] = z;
        ones[cnt] = o;
        cnt++;
    }

    for (int i = 0; i < (m + n - 1) / 2; i++) {
        int z = zeros[i] + zeros[m + n - 2 - i];
        int o = ones[i] + ones[m + n - 2 - i];
        res += (min(z, o));
    }

    cout << res << endl;
}

signed main() {
    OJ();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    if (true)
        cin >> tt;
    while (tt--) lego();

    return 0;
}