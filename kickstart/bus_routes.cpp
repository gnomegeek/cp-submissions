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
    bool is_possible(int startday, int a[], int maxd, int n) {
        int days_passed = startday;
        for (int i = 0; i < n; i++) {
            if (days_passed % a[i] == 0) {
                continue;
            } else {
                days_passed += a[i] - (days_passed % a[i]);
            }
        }
        if (days_passed <= maxd) return true;
        return false;
    }

    void test_case(int test) {
        int n, d;
        cin >> n >> d;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int s = 0;
        int e = d;
        int ans;
        while (s <= e) {
            int mid = mid(s, e);
            if (is_possible(mid, a, d, n)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        cout << "Case #" << test << ": " << ans << endl;
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