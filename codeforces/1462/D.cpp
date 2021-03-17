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
    int n, sum = 0, root;
    cin >> n;

    vector<int> v(n);
    vector<int> kvals;

    for (int &e : v) {
        cin >> e;
        sum += e;
    }
    root = sqrt(sum);

    for (int i = 1; i <= root; i++) {
        if (sum % i == 0) {
            kvals.push_back(n - i);
            if (i * i != sum and n >= sum / i)
                kvals.push_back(n - sum / i);
        }
    }

    sort(kvals.begin(), kvals.end());

    // for (int i : kvals) cout << i << " ";
    // cout << endl;
    for (auto i = kvals.begin(); i != kvals.end(); ++i) {
        int cur_sum = 0, req_sum = sum / (n - (*i)), cnt = 0;
        for (int j : v) {
            cur_sum += j;
            if (cur_sum == req_sum) {
                cnt++;
                cur_sum = 0;
            } else if (cur_sum > req_sum)
                break;
        }
        if (cnt == n - (*i)) {
            cout << *i << endl;
            return;
        }
    }
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