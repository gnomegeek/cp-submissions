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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<pair<int, int>> segs;
        bool start_search = true, end_search = false;
        for (int i = 1; i < n; i++) {
            if (start_search) {
                if (a[i] < a[i - 1]) {
                    segs.push_back({i, INT_MAX});
                    start_search = false;
                    end_search = true;
                }
            } else {
                if (a[i] > a[i - 1]) {
                    segs[segs.size() - 1].second = i - 1;
                    start_search = true;
                    end_search = false;
                }
            }
        }

        if (end_search) {
            segs[segs.size() - 1].second = n - 1;
        }

        int res = 0;

        for (auto i : segs) {
            res += (a[i.first - 1] - a[i.second]);
            if (a[i.first] + a[i.first - 1] - a[i.second] < a[i.first - 1]) {
                res += a[i.first] - a[i.second];
            }
        }
        cout << res << endl;
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