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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int startWinIdx = -1, endWinIdx = -1, last = -1;
    int points = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            if (startWinIdx == -1) startWinIdx = i;
            if (last == 1)
                points += 2;
            else
                points += 1;
            last = 1;
            endWinIdx = i;
        } else {
            last = 0;
        }
    }

    if (k == 0) {
        cout << points << endl;
        return;
    }

    if (startWinIdx == -1) {
        points += (2 * (min(k, n)) - 1);
        cout << points << endl;
        return;
    }

    if (startWinIdx == endWinIdx) {
        int left = startWinIdx;
        int right = n - endWinIdx - 1;
        points += min(k, left + right) * 2;
        cout << points << endl;
        return;
    }

    vector<int> clusters;
    int loss = 0;
    for (int i = startWinIdx; i <= endWinIdx; i++) {
        if (s[i] == 'W') {
            if (loss != 0) clusters.push_back(loss);
            loss = 0;
        } else {
            loss++;
        }
    }

    sort(clusters.begin(), clusters.end());

    for (auto i : clusters) {
        if (i <= k) {
            k -= i;
            points += (i * 2 + 1);
        } else {
            points += (2 * k);
            k = 0;
            break;
        }

        if (k == 0) break;
    }

    if (k != 0) {
        int left = startWinIdx;
        int right = n - endWinIdx - 1;
        points += min(k, left + right) * 2;
    }

    cout << points << endl;
    return;
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