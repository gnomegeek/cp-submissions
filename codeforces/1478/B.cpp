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
        int n, d;
        cin >> n >> d;
        while (n--) {
            int x;
            cin >> x;
            int done = 0;
            int xc = x;
            if (x >= 10 * d) {
                cout << "yes" << endl;
                done = 1;
            }
            if (done) continue;
            if (d == 1) {
                cout << "yes" << endl;
                done = 1;
            }
            if (done) continue;
            while (xc != 0) {
                int dig = xc % 10;
                xc = xc / 10;
                if (dig == d) {
                    cout << "yes" << endl;
                    xc = 0;
                    done = 1;
                }
            }

            if (done) continue;

            int lastdig = x % 10;

            int sum = d;

            for (int i = 1; i <= 10; i++) {
                if ((x - sum) % 10 == 0 and sum <= x) {
                    cout << "yes" << endl;
                    i = 11;
                    done = 1;
                }
                sum += d;
            }
            if (!done) cout << "no" << endl;
        }
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