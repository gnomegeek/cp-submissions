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

void __init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {
    __init();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1];
        vector<pair<int, int>> whites;

        // Input and updates whites
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char ch;
                cin >> ch;
                if (ch == '1')
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
                if (a[i][j] == 1) whites.PB(make_pair(i, j));
            }
        }

        // Main Logic BruteForce
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 0) {
                    int res = INT_MAX;
                    for (auto k : whites) {
                        int whiteI = k.FF;
                        int whiteJ = k.SS;
                        res = min(res, abs(whiteI - i) + abs(whiteJ - j));
                    }
                    a[i][j] = res;
                }
            }
        }

        // Updating all the original whites to 0
        for (auto k : whites) {
            a[k.FF][k.SS] = 0;
        }

        // Output
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}