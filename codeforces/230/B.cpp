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

struct test_cases {
    static const int N = 1000000;
    bitset<N> b;
    void sieve() {
        b.set();
        b[0] = 0;
        b[1] = 0;

        for (int i = 2; i * i <= N; i++) {
            if (b[i]) {
                int k = i * i;
                while (k <= N) {
                    b[k] = 0;
                    k += i;
                }
            }
        }
    }
    void test_case() {
        int n;
        sieve();
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int root = sqrt(a[i]);
            if (b[root]) {
                if (root * root == a[i]) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                cout << "NO" << endl;
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
    for (int i = 0; i < tc; i++) {
        struct test_cases o;
        o.test_case();
    }
    return 0;
};