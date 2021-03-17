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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int curH = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (i != n - 1) {
                int uptime = a[i] - curH;
                int eattime = 1;
                int downtime;
                if (a[i + 1] >= a[i]) {
                    curH = a[i];
                    downtime = 0;
                } else {
                    curH = a[i + 1];
                    downtime = a[i] - a[i + 1];
                }
                res = res + uptime + eattime + downtime;
            } else {
                int uptime = a[i] - curH;
                int eattime = 1;
                res += uptime + eattime;
            }
        }

        res += n - 1;
        cout << res << endl;
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