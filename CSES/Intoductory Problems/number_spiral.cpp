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
        int x, y;
        cin >> y >> x;
        cout << endl;
        if (x == y) {
            cout << x * x - x + 1;
            return;
        }

        int cp;
        if (x > y) {
            if (x % 2 != 0) {
                cp = x * x;
                cout << cp - y + 1;
                return;
            } else {
                cp = (x - 1) * (x - 1) + 1;
                cout << cp + y - 1;
                return;
            }
        } else {
            if (y % 2 == 0) {
                cp = y * y;
                cout << cp - x + 1;
                return;
            } else {
                cp = (y - 1) * (y - 1) + 1;
                cout << cp + x - 1;
                return;
            }
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