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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int csum[n];
    csum[0] = a[0];
    vector<int> mp(21000000);
    int offset = 10500000;
    mp[0 + offset] = 1;
    int mn = 0, res = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0) csum[i] = csum[i - 1] + a[i];
        mn = min(mn, csum[i]);
        for (int j = 0; j * j <= (csum[i] - mn); j++)
            res += mp[csum[i] - j * j + offset];
        mp[csum[i] + offset]++;
    }
    cout << "Case #" << test << ": " << res << endl;
}

void speeeeeeeeeed() {
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