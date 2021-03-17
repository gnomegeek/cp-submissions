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
        int sum = n * (n + 1) / 2;
        if (sum & 1) {
            cout << "NO" << endl;
            return;
        }

        int req = sum / 2;

        cout << "YES" << endl;
        vector<int> v1, v2;
        for (int i = n; i > 0; i--) {
            if (req >= i) {
                req -= i;
                v1.push_back(i);
            } else {
                v2.push_back(i);
            }
        }

        cout << v1.size() << endl;
        for (auto i : v1) cout << i << " ";
        cout << endl << v2.size() << endl;
        for (auto i : v2) cout << i << " ";
        cout << endl;
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