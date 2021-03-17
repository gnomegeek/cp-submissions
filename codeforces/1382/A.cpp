#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge                   \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void additionals() {
    // FastIO;
    // OnlineJudge;
}

void solve(int n, int m) {
    int freq[1001];
    int res = 0, x;
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++) {
        cin >> x;
        freq[x]++;
    }

    for (int i = 0; i < m; i++) {
        cin >> x;
        if (freq[x] > 0) {
            res = x;
        }
    }

    if (res != 0) {
        cout << "YES" << endl;
        cout << "1 " << res << endl;
    } else {
        cout << "NO" << endl;
    }
}
void ok() {
    int n, m, freq[1001];
    cin >> n >> m;
    solve(n, m);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        ok();
    }
    return 0;
}