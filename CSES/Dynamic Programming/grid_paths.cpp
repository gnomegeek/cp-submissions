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
    void test_case(int test) {
        int n;
        cin >> n;
        int mat[n][n];
        int dp[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char ch;
                cin >> ch;
                if (ch == '.')
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
        }
        int fl = 0, fb = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 0) fl = true;

            if (mat[0][i] == 0) fb = true;

            if (fl)
                dp[i][0] = 0;
            else
                dp[i][0] = 1;

            if (fb)
                dp[0][i] = 0;
            else
                dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                else {
                    int op1 = mat[i][j - 1] == 0 ? 0 : dp[i][j - 1];
                    int op2 = mat[i - 1][j] == 0 ? 0 : dp[i - 1][j];
                    dp[i][j] = (op1 + op2) % MOD;
                }
            }
        }

        cout << dp[n - 1][n - 1] % MOD << endl;
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