/* 
    Common Techniques:
    - Two Pointers
    - Binary Search
    - DP
    - Graph
    - Bitmasking
    - Divide and Conquer
    - Recursion

    Think Think Think !!!!
*/

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define int long long
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    wowset;

const int INF = 1e8;
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int modd = 998244353;
const string yess = "YES";
const string noo = "NO";
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int maxn = 2e5 + 100;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int fastexpo(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base);
        exp = exp >> 1;
        base = (base * base);
    }
    return res;
}

int mod_div(int a, int b) { return a * fastexpo(b, mod - 2) % mod; }

bool cases = 0;

char mat[8][8];

int res = 0;

bool check(int a[8][8]) {
    int ld = 1, rd = 1;

    for (int i = 0; i < 8; i++) {
        int x = i, y = 0;
        int cnt = 0;
        while (x < 8 and y < 8) {
            if (a[x][y]) cnt++;

            x++;
            y++;
        }

        if (cnt > 1) ld = 0;
    }

    for (int j = 0; j < 8; j++) {
        int x = 0, y = j;
        int cnt = 0;
        while (x < 8 and y < 8) {
            if (a[x][y]) cnt++;

            x++;
            y++;
        }

        if (cnt > 1) ld = 0;
    }

    for (int i = 0; i < 8; i++) {
        int x = i, y = 7;
        int cnt = 0;
        while (x < 8 and y >= 0) {
            if (a[x][y]) cnt++;

            x++;
            y--;
        }

        if (cnt > 1) rd = 0;
    }

    for (int j = 0; j < 8; j++) {
        int x = 0, y = j;
        int cnt = 0;
        while (x < 8 and y >= 0) {
            if (a[x][y]) cnt++;

            x++;
            y--;
        }

        if (cnt > 1) rd = 0;
    }

    return (rd and ld);
}

void place(int i, int cur[8][8], int mask) {
    if (i == 8) {
        if (mask == 255) {
            bool ok = check(cur);
            if (ok) res++;
        }
        return;
    }

    for (int j = 0; j < 8; j++) {
        if (mat[i][j] == '.' and !((mask >> (7 - j)) & 1)) {
            cur[i][j] = 1;
            place(i + 1, cur, mask | (1 << (7 - j)));
            cur[i][j] = 0;
        }
    }
}

void letsGO(int test) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> mat[i][j];

    int cur[8][8] = {0};

    place(0, cur, 0);

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(6);
    int TT = 1, cnt = 0;
    if (cases) cin >> TT;
    while (TT--) letsGO(++cnt);
}