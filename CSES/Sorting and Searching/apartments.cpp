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

// n applicants, m apartments

struct test_cases {
    void test_case(int test) {
        int n, m, k;
        cin >> n >> m >> k;
        int desired[n], available[m];
        for (int i = 0; i < n; i++) cin >> desired[i];
        for (int i = 0; i < m; i++) cin >> available[i];

        sort(desired, desired + n);
        sort(available, available + m);

        // i -> desired
        // j -> available
        int j = 0, i = 0;
        int res = 0;
        while (j != m) {
            if (desired[i] + k >= available[j] and
                desired[i] - k <= available[j]) {
                i++;
                j++;
                res++;
            } else if (desired[i] > available[j]) {
                j++;
            } else {
                i++;
            }
        }

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
        o.test_case(i + 1);
    }
    return 0;
};