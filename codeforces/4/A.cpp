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
    int w;
    cin >> w;
    if (w == 2 || w == 0) {
        cout << "NO" << endl;
        return 0;
    }

    if (w % 2 == 0) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}