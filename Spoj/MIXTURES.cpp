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

int solve(vector<int> arr, vector<int> cumSum, int i, int j, int dp[101][101]) {
    if (i == j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int temp = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        int smoke1 = solve(arr, cumSum, i, k, dp);
        dp[i][k] = smoke1;
        int smoke2 = solve(arr, cumSum, k + 1, j, dp);
        dp[k + 1][j] = smoke2;
        int smoke3;
        int sumLeftHalf = cumSum[k] - cumSum[i] + arr[i];
        int sumRightHalf = cumSum[j] - cumSum[k];
        smoke3 = (sumLeftHalf % 100) * (sumRightHalf % 100);
        temp = min(temp, smoke3 + smoke1 + smoke2);
    }

    return dp[i][j] = temp;
}

int32_t main() {
    __init();
    int n;
    while (cin >> n) {
        vector<int> col, cumSum;

        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            col.PB(c);
            if (i == 0) {
                cumSum.PB(c);
            } else {
                cumSum.PB(*(--cumSum.end()) + c);
            }
        }

        int dp[101][101];
        memset(dp, -1, sizeof(dp));

        cout << solve(col, cumSum, 0, n - 1, dp) << endl;
    }
    return 0;
}