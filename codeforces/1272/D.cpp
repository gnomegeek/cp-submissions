#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define int long long
#define ump unordered_map
#define endl "\n"
#define mod 10000000

void OJ() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

template <typename T>
bool is_sorted(T a[], int n) {
    if (n == 1) return true;
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / (gcd(a, b));
}

void lego() {
    int n;
    cin >> n;
    int a[n + 1];

    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = -inf;

    vector<pair<int, int>> v;
    int left = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] >= a[i]) {
            if (left != (i - 1)) {
                v.push_back({left, i - 1});

                res = max(res, (i - left));
            }
            left = i;
        }
    }
    if (left != n) {
        v.push_back({left, n});
        res = max(res, n - left + 1);
    }

    if(res == -inf) {
        cout << 1 << endl;
        return;
    }

    // for (auto i : v) cout << i.first << " " << i.second << endl;

    // cout << res << endl;


    for (int i = 1; i < v.size(); i++) {
        int start = v[i].first;
        int end = v[i].second;

        bool canJoinLeft = true;
        if (v[i].first - v[i - 1].second > 2) canJoinLeft = false;
        if (!canJoinLeft) continue;



        if (v[i].first - v[i - 1].second == 1) {
            if (v[i - 1].second == v[i - 1].first || v[i].first == v[i].second) continue;

            else {
                if (a[v[i - 1].second - 1] < a[v[i].first] || a[v[i - 1].second] < a[v[i].first + 1]) {
                    res = max(res, v[i - 1].second - v[i - 1].first + 1 + v[i].second - v[i].first);
                }
            }
        } else {
            if (a[v[i].first] > a[v[i - 1].second])
                res = max(res, v[i - 1].second - v[i - 1].first + 1 + v[i].second - v[i].first + 1);
        }


    }

    cout << res << endl;
}

signed main() {
    OJ();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    if (false)
        cin >> tt;
    while (tt--) lego();

    return 0;
}