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

int main() {
    FastIO;
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    int res = 0;
    // FF->x
    // SS->y
    for (int i = 0; i < v.size(); i++) {
        int lower = 0, upper = 0, left = 0, right = 0;
        for (int j = 0; j < v.size(); j++) {
            if (j == i) continue;

            if (v[i].FF == v[j].FF && v[i].SS < v[j].SS) lower = 1;
            if (v[i].FF == v[j].FF && v[i].SS > v[j].SS) upper = 1;
            if (v[i].FF < v[j].FF && v[i].SS == v[j].SS) left = 1;
            if (v[i].FF > v[j].FF && v[i].SS == v[j].SS) right = 1;

            if (left == 1 && right == 1 && upper == 1 && lower == 1) {
                j = v.size();
                res++;
            }
        }
    }
    cout << res;

    return 0;
}