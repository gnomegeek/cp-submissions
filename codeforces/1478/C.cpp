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
        int x[2 * n];
        int d[n];
        for (int i = 0; i < 2 * n; i++) {
            cin >> x[i];
        }

        sort(x, x + 2 * n);
        for (int i = 0; i < 2 * n; i += 2) {
            if (x[i] != x[i + 1]) {
                cout << "no" << endl;
                return;
            } else {
                d[i / 2] = x[i];
            }
        }

        int sum = 0;
        int a[n];

        for (int k = n - 1; k >= 0; k--) {
            if ((d[k] - 2 * sum) % (2 * (k + 1)) == 0) {
                a[k] = (d[k] - 2 * sum) / (2 * (k + 1));
                sum += a[k];
                if (a[k] <= 0) {
                    cout << "no" << endl;
                    return;
                }
            } else {
                cout << "no" << endl;
                return;
            }
        }

        sort(a, a + n);
        for (int k = 0; k < n - 1; k++) {
            if (a[k] == a[k + 1]) {
                cout << "no" << endl;
                return;
            }
        }

        cout << "yes" << endl;
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