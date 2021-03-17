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
    int A, B, n;
    cin >> A >> B >> n;
    vector<pair<int, int>> info(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        info[i].first = x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        info[i].second = x;
    }

    sort(info.begin(), info.end());
    int fights_req = 0;
    int negB = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = fights_req;
        fights_req += info[i].second / A;
        if (info[i].second % A != 0) fights_req++;
        negB += (fights_req - x) * info[i].first;
        if (negB >= B) {
            cout << "NO" << endl;
            return;
        }
    }

    if (negB >= B) {
        cout << "NO" << endl;
        return;
    }

    int freq = info[n - 1].second / A;
    if (info[n - 1].second % A != 0) freq++;
    int fava = (B - negB) / info[n - 1].first;
    if ((B - negB) % info[n - 1].first != 0) fava++;

    if (fava >= freq) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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