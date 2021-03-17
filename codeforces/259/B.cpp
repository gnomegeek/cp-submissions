#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
#define endl "\n"
#define int long long
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define mid(s, e) ((s + (e - s) / 2))

bool test_cases;

void init(bool k) {
    test_cases = k;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct precompute {
    void compute() {
    }
};

struct test_cases {
    void test_case() {
        int a, b, c, d, e, f, g, h, i;
        cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
        for (int i = 1; i < 100001; i++) {
            int x = i;
            int y = x + b + c - d - f;
            int z = x + b + c - g - h;
            if (x + d + g == b + y + h && b + y + h == c + f + z && b + y + h == x + y + z && x + y + z == c + y + g) {
                cout << x << " " << b << " " << c << endl;
                cout << d << " " << y << " " << f << endl;
                cout << g << " " << h << " " << z << endl;
                return;
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
        o.test_case();
    }
    return 0;
};