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

int n;
vector<int> tre[maxn];

vector<int> depths(maxn, -1);

vector<int> lengths(maxn, -1);

int calculateDepths(int i, int parent) {
    int temp = 0;

    if (depths[i] != -1) return depths[i];

    for (int j : tre[i]) {
        if (j != parent) {
            temp = max(temp, calculateDepths(j, i));
        }
    }

    return depths[i] = temp + 1;
}

int calculateDia(int i, int parent) {
    multiset<int> s;
    s.insert(-1);
    s.insert(-1);
    for (int j : tre[i]) {
        if (parent != j) {
            s.insert(depths[j]);
            if (s.size() > 2) s.erase(s.begin());
        }
    }

    lengths[i] = *s.begin() + *(--s.end()) + 2;

    for (int j : tre[i]) {
        if (parent != j) {
            calculateDia(j, i);
        }
    }
}

void letsGO(int test) {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tre[a].pb(b);
        tre[b].pb(a);
    }

    calculateDepths(1, -1);

    for (int i = 1; i <= n; i++) depths[i]--;

    calculateDia(1, -1);

    int val = 0;
    for (int i = 1; i <= n; i++)
        val = max(val, lengths[i]);

    cout << val << endl;
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