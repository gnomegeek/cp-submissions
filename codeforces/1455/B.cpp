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

int solve(int s, int e, int i) {
    if (s - 1 < -e) return inf;
    if (s == e) return 0;
    if (s > e) return s - e;
    int op1 = solve(s + i, e, i + 1), op2;
    op2 = solve(s - 1, e, i + 1);
    return 1 + min(op1, op2);
}

void lego() {
    int x;
    cin >> x;
    int steps = 1;
    while (steps * (steps + 1) < 2 * x) {
        steps++;
    }
    if (steps * (steps + 1) == 2 * x) {
        cout << steps << endl;
        return;
    }
    if ((steps * (steps + 1)) / 2 - x > 1) {
        cout << steps << endl;
        return;
    } else {
        cout << steps + 1 << endl;
        return;
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