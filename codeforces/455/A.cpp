#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
#define endl "\n"
#define int long long
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define mid(s, e) ((s + (e - s) / 2))

bool test_cases;

void init(bool k) {
    test_cases = k;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct precompute {
    void compute() {
    }
};

struct test_cases {
    void test_case() {
        int n;
        cin >> n;
        // int freq[100001];
        int dp[100001][2];

        unordered_map<int, int> freq;
        int mx = INT_MIN;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > mx) mx = x;
            if (freq.find(x) != freq.end()) {
                freq[x]++;
            } else {
                freq[x] = 1;
            }
        }

        dp[0][0] = dp[0][1] = 0;

        for (int i = 1; i <= mx; i++) {
            int k = i;
            int f = freq[i];
            dp[k][0] = dp[k - 1][1] + f * k;
            dp[k][1] = max(dp[k - 1][0], dp[k - 1][1]);
        }

        for (int i = 0; i < mx; i++) {
        }

        cout << max(dp[mx][0], dp[mx][1]);
    }
};

int32_t main() {
    init(false);
    int tc;
    if (test_cases) {
        cin >> tc;
    } else {
        tc = 1;
    }
    struct precompute l;
    l.compute();
    for (int i = 0; i < tc; i++) {
        struct test_cases o;
        o.test_case();
    }
    return 0;
};