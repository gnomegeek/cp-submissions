#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
#define inputArray(a, n) \
    for (int i = 0; i < n; i++) cin >> a[i];
#define printArray(a, n) \
    for (int i = 0; i < n; i++) cout << a[i] << endl;
typedef pair<int, int> pii;
#define endl "\n"
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
// #define int long long
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define clr(val, val1) memset(val, val1, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OnlineJudge                   \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void additionals() {
    FastIO;
    OnlineJudge;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, old;
        cin >> n;
        vector<int> v;
        cin >> x;
        old = x;
        v.PB(x);
        for (int i = 1; i < n; i++) {
            cin >> x;
            if (x == 1 && old == 1) {
                v.pop_back();
                old = -1;
            } else {
                old = x;
                v.PB(x);
            }
        }

        // for (auto i : v) cout << i << " ";

        if (!v.empty()) {
            if (v[0] == 1 && v.size() > 1) {
                cout << "Second" << endl;
            } else {
                cout << "First" << endl;
            }
        } else {
            cout << "Second" << endl;
        }
    }
    return false;
}