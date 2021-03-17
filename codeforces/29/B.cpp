#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
#define fo(i, j, k, in) for (int i = j; i < k; i += in)
#define inputArray(a, n) \
    for (int i = 0; i < n; i++) cin >> a[i];
#define printArray(a, n) \
    for (int i = 0; i < n; i++) cout << a[i] << endl;
#define Sld(t) scanf("%ld", &t)
#define scc(t) scanf("%c", &t)
#define sf(t) scanf("%f", &t)
#define slf(t) scanf("%lf", &t)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define clr(val, val1) memset(val, val1, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

double waitFor(double g, double r, double t) {
    while (t >= g + r) {
        t = t - g - r;
    }
    if (t == g) {
        return r;
    }
    if (t > g) {
        return r + g - t;
    }
    if (t < g) {
        return 0;
    }
    return 0;
}

int main() {
    FastIO;
    double l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;

    if (d / v < g) {
        cout << fixed << setprecision(8) << l / v << endl;
    } else {
        double res = l / v + waitFor(g, r, d / v);
        cout << fixed << setprecision(8) << res << endl;
    }

    return 0;
}