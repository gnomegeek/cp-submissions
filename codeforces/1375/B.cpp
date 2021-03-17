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

int neigh(int a[301][301], int n, int m, int i, int j) {
    int numberOfNeigh;
    if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        // extreme corner
        if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
            numberOfNeigh = 2;
        } else {
            numberOfNeigh = 3;
        }
    } else {
        if (n == 2 && m == 2) {
            numberOfNeigh = 2;
        } else if ((n == 2 && m == 3) || (n == 3 && m == 2)) {
            numberOfNeigh = 3;
        } else {
            numberOfNeigh = 4;
        }
    }
    return numberOfNeigh;
}

int32_t main() {
    __init();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[301][301];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        bool noAnswer = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k = a[i][j];
                if (true) {
                    int totalNeigh = neigh(a, n, m, i, j);
                    if (totalNeigh < k) {
                        cout << "NO" << endl;
                        noAnswer = true;
                        j = INT_MAX;
                        i = INT_MAX;
                    } else {
                        a[i][j] = totalNeigh;
                    }
                }
            }
        }
        if (!noAnswer) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}