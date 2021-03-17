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

struct test_cases {
    void test_case(int test) {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int left = 0;
        int right = 0;
        int curr_sum = a[0];
        int res = 0;
        while (left <= right) {
            if (curr_sum == m) {
                cout << m << endl;
                return;
            } else if (curr_sum < m) {
                res = max(curr_sum, res);
                right++;
                curr_sum += a[right];
                if (right == n) {
                    break;
                }
            } else {
                curr_sum -= a[left];
                left++;
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