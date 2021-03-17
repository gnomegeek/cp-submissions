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
        if (n == 1) {
            cout << 1;
            return;
        }
        if (n == 4) {
            cout << "2 4 1 3";
            return;
        }
        if (n < 5) {
            cout << "NO SOLUTION" << endl;
            return;
        }

        if (n % 2 != 0) {
            cout << n / 2 + 1 << " ";
            for (int i = 1; i <= n / 2; i++) {
                cout << i << " " << i + n / 2 + 1 << " ";
            }

        } else {
            for (int i = 1; i <= n / 2; i++) {
                cout << i << " " << i + n / 2 << " ";
            }
        }
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
