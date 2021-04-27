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

#define int long long
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    wowset;

const int INF = 1e18;
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

void letsGO(int test) {
    string s;

    cin >> s;

    int cnt[26] = {0};

    for (char ch : s) cnt[ch - 'A']++;

    int odd = 0, evens = 0;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 0) {
            evens++;
        } else {
            odd++;
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    if (odd == 1) {
        int idx = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 != 0) {
                idx = i;
            } else {
                for (int j = 0; j < cnt[i] / 2; j++) {
                    cout << (char)(i + 'A');
                }
            }
        }

        for (int i = 0; i < cnt[idx]; i++) {
            cout << (char)(idx + 'A');
        }
        cnt[idx] = 0;

        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }

        cout << endl;
        return;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i] / 2; j++) {
            cout << (char)(i + 'A');
        }
    }

    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < cnt[i] / 2; j++) {
            cout << (char)(i + 'A');
        }
    }

    return;
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