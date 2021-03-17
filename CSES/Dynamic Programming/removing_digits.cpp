#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
#define endl "\n"
#define int long long
#define MOD 1000000007
#define ump unordered_map
#define pb push_back
#define mp make_pair
#define pie acos(-1)
#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define mid(s, e) ((s + (e - s) / 2))

bool test_cases;

struct precompute {
    void compute() {}
};

void init(bool k) {
    test_cases = k;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int dp[1000001];

struct test_cases {
    int minSteps(int n) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        int nc = n, x1 = INT_MAX;
        while (nc != 0) {
            int dig = nc % 10;
            nc /= 10;
            if (n - dig >= 0 and dig != 0) {
                x1 = min(x1, 1 + minSteps(n - dig));
            }
        }

        return dp[n] = x1;
    }

    void test_case(int test) {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << minSteps(n) << endl;
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
        o.test_case(i + 1);
    }
    return 0;
};