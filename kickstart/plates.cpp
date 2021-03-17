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
    void compute() {
    }
};

void init(bool k) {
    test_cases = k;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int dp[100][2000];

struct test_cases {
    int max_beauty(vector<vector<int>>& stacks, int i, int n, int k, int p) {
        if (i == n) return 0;
        if (p <= 0) return 0;

        if (dp[i][p] != -1) return dp[i][p];

        int if_not_selected = max_beauty(stacks, i + 1, n, k, p);
        dp[i + 1][p] = if_not_selected;
        int temp = INT_MIN;
        for (int j = 0; j < k and j + 1 <= p; j++) {
            int aage_ki_beauty = max_beauty(stacks, i + 1, n, k, p - j - 1);
            dp[i + 1][p - j - 1] = aage_ki_beauty;
            int curr_beauty = stacks[i][j];
            temp = max(temp, max(curr_beauty + aage_ki_beauty, if_not_selected));
        }

        return dp[i][p] = temp;
    }

    void test_case(int test) {
        memset(dp, -1, sizeof(dp));
        int n, k, p;
        cin >> n >> k >> p;
        vector<vector<int>> stacks(n, vector<int>(k));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cin >> stacks[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < k; j++) {
                sum = sum + stacks[i][j];
                stacks[i][j] = sum;
            }
        }

        cout << "Case #" << test << ": " << max_beauty(stacks, 0, n, k, p) << endl;
    }
};

int32_t main() {
    init(true);
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