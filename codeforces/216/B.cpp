/*
    Author: Vatsal Agarwal
    Birla Institute of Technology and Sciences, Pilani, Goa Campus

    Make it work, make it right, make it fast.
*/

#include <bits/stdc++.h>
using namespace std;
typedef int itn;
#define int long long
#define inf INT_MAX
#define umap unordered_map
#define endl "\n"
#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define mid(s, e) ((s + (e - s) / 2))
#define mod 1000000007
#define scArray(a, b) \
    for (int i = 0; i < b; i++) cin >> a[i]
void OJ() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// assign 1 to tt for testcases
int TT = 0;

bool dfs(umap<int, list<int>> l, int colors[], int i, int color, int cameFrom) {
    colors[i] = color;
    for (auto j : l[i]) {
        if (colors[j] == 0) {
            bool res = dfs(l, colors, j, 3 - color, i);
            if (!res) return false;
        } else if (j != cameFrom and colors[j] == color) {
            return false;
        }
    }

    return true;
}

void lego() {
    int n, m;
    cin >> n >> m;
    umap<int, list<int>> l;
    for (int i = 1; i <= n; i++) l[i] = {};
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        l[a].push_back(b);
        l[b].push_back(a);
    }

    int colors[n + 1] = {0}, cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0) {
            if (!dfs(l, colors, i, 1, -1)) cnt++;
        }
    }

    if ((n - cnt) % 2 != 0) cnt++;

    cout << cnt << endl;
}

signed main() {
    OJ();
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