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
        int n;
        cin >> n;
        int gm100 = 0;
        int gm200 = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 100) gm100++;
            if (x == 200) gm200++;
        }

        int wtin1 = (gm100 * 100 + gm200 * 200) / 2;
        int s1 = 0;
        while (gm200 && s1 < wtin1) {
            s1 += 200;
            gm200--;
        }
        if (s1 == wtin1) {
            cout << "YES" << endl;
            return;
        } else {
            if (s1 > 0)
                s1 -= 200;
            while (s1 < wtin1 && gm100) {
                s1 += 100;
                gm100--;
            }
            if (s1 == wtin1) {
                cout << "YES" << endl;
                return;
            } else {
                cout << "NO" << endl;
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