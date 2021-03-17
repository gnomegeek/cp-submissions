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
        int n, x, y;
        cin >> n >> x >> y;
        int a, b;
        a = x;
        b = y;
        x = max(a, b);
        y = min(a, b);
        vector<int> v;
        if (n == 2) {
            cout << x << " " << y << endl;
            return;
        }
        int k = n - 1;
        while ((x - y) % k != 0) {
            k--;
        }

        int d = (x - y) / k;
        int cnt = 0;
        for (int i = y; i <= x; i += d) {
            cnt++;
            cout << i << " ";
        }
        int i = y - d;
        while (cnt != n and i > 0) {
            cnt++;
            cout << i << " ";
            i -= d;
        }

        if (cnt == n) {
            cout << endl;
            return;
        }

        i = x + d;
        while (cnt != n) {
            cout << i << " ";
            cnt++;
            i += d;
        }

        cout << endl;
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