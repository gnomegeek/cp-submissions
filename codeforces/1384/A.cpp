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
        int n, length = INT_MIN;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            length = max(length, a[i]);
        }

        vector<string> res;
        string s(length, 'a');
        if (length == 0) {
            length = 1;
            res.PB("a");
        } else {
            res.PB(s);
        }
        for (int i = 0; i < n; i++) {
            string k = "";
            for (int j = 0; j < a[i]; j++) {
                k = k + res[i][j];
            }
            if (a[i] != length) {
                if (res[i][k.length()] == 'a') {
                    string p(length - k.length(), 'b');
                    k = k + p;
                } else {
                    string p(length - k.length(), 'a');
                    k = k + p;
                }
            }
            res.PB(k);
        }
        for (auto i : res) cout << i << endl;
    }
    return 0;
}