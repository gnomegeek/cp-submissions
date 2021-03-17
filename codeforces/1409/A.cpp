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

bool test_cases;

void init(bool k) {
    test_cases = k;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct test_cases {
    void test_case(int test) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << endl;
            return;
        }
        int cnt = 0;
        if (a > b) {
            for (int i = 10; i >= 1; i--) {
                cnt += (a - b) / i;
                a -= ((a - b) / i) * i;
            }
        } else {
            for (int i = 10; i >= 1; i--) {
                cnt += (b - a) / i;
                b -= ((b - a) / i) * i;
            }
        }

        cout << cnt << endl;
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
    for (int i = 0; i < tc; i++) {
        struct test_cases o;
        o.test_case(i + 1);
    }
    return 0;
};