#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

const int LINF = 1e18;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const int MOD2 = 998244353;

int gcd(int a, int b), lcm(int a, int b), expo(int e, int n);

bool cases = true;

void letsGO(int test) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "$" + s;

    int cnt = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (s[i] == s[n - i + 1]) {
            cnt++;
        }
    }

    int score = n / 2 - cnt;

    int res = abs(score - k);

    cout << "Case #" << test << ": " << res << endl;
}

void speeeeeeeeeed() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int expo(int e, int n) {
    return n ? n & 1 ? e * expo(e, --n) : expo(e * e, n / 2) : 1;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

signed main() {
    speeeeeeeeeed();
    cout << fixed << setprecision(10);
    int TT = 1, cnt = 0;
    if (cases) cin >> TT;
    while (TT--) letsGO(++cnt);
}