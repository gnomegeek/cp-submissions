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
    int n, x;
    cin >> n;
    vector<int> odds, evens;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x & 1)
            odds.push_back(x);
        else
            evens.push_back(x);
    }

    sort(odds.begin(), odds.end(), greater<int>());
    sort(evens.begin(), evens.end(), greater<int>());

    int alice = 0, bob = 0, turn = 1;
    auto i = odds.begin(), j = evens.begin();
    while (i != odds.end() and j != evens.end()) {
        if (*i > *j) {
            if (!turn)
                bob += *i;
            i++;
        } else {
            if (turn)
                alice += *j;
            j++;
        }
        turn = !turn;
    }

    while (j != evens.end()) {
        if (turn) alice += *j;
        j++;
        turn = !turn;
    }

    while (i != odds.end()) {
        if (!turn) bob += *i;
        i++;
        turn = !turn;
    }

    if (alice > bob) {
        cout << "Alice";
    } else if (alice < bob) {
        cout << "Bob";
    } else {
        cout << "Tie";
    }

    cout << endl;
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