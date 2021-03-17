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

struct test_cases {
    int dp[1000002];

    int numWays(int a[], int n, int makeMoney) {
        if (makeMoney == 0) return 1;

        if (dp[makeMoney] != -1) return dp[makeMoney];
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (makeMoney - a[i] < 0) {
                continue;
            }
            temp += numWays(a, n, makeMoney - a[i]) % MOD;
        }

        return dp[makeMoney] = (temp % MOD);
    }

    void test_case(int test) {
        int n, makeMoney;
        cin >> n >> makeMoney;
        int a[n];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) cin >> a[i];
        int x = numWays(a, n, makeMoney);
        cout << (x == INT_MAX ? -1 : x) << endl;
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