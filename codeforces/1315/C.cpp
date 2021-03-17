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
#define int long long
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define clr(val, val1) memset(val, val1, sizeof(val))
// #define LOCAL

void __init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {
    __init();
    int t;
    cin >> t;
    while (t--) {
        int n, printed = 0;
        cin >> n;
        int b[n + 1], a[2 * n + 1];
        int freq[201];
        clr(freq, 0);
        for (int i = 0; i < n; i++) {
            cin >> b[i + 1];
            freq[b[i + 1]]++;
            a[2 * (i + 1) - 1] = b[i + 1];
        }

        for (int i = 2; i < 2 * n + 1; i += 2) {
            for (int j = a[i - 1]; j < 201; j++) {
                if (freq[j] == 0) {
                    if (j <= 2 * n) {
                        freq[j]++;
                        a[i] = j;
                        j = 202;
                    } else {
                        cout << -1;
                        j = INT_MAX;
                        i = INT_MAX;
                        printed = 1;
                    }
                }
            }
        }

        if (printed != 1) {
            for (int i = 1; i < 2 * n + 1; i++) {
                if (a[i] > 201 || a[i] <= 0) {
                    cout << -1;
                    i = INT_MAX;
                    printed = 1;
                }
            }
        }

        if (printed != 1) {
            for (int i = 1; i < 2 * n + 1; i++) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}