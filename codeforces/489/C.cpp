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
        int m, sum;
        cin >> m >> sum;
        if (m == 1 and sum == 0) {
            cout << 0 << " " << 0 << endl;
            return;
        }
        string mx = "", mn = "";
        int flag = 0;
        int cnt = 0;
        while (sum >= 0 && cnt != m) {
            if (sum != 0) {
                int k = min(9, sum);
                if (k == 9) {
                    mx += '9';
                    sum = sum - 9;
                } else {
                    mx += (char)(sum + 48);
                    sum = 0;
                }
            } else {
                mx += '0';
            }
            cnt++;
        }

        if (sum != 0) {
            cout << -1 << " " << -1 << endl;
            return;
        }

        string res = mx;

        if (mx[m - 1] != '0') {
            for (int i = m - 1; i >= 0; i--) {
                cout << mx[i];
            }
            cout << " " << res << endl;
            return;
        }

        for (int i = m - 1; i >= 0; i--) {
            if (mx[i] != '0') {
                flag = 1;
                mx[i] -= 1;
                mx[m - 1] = '1';
                break;
            }
        }
        if (flag == 0) {
            cout << -1 << " " << -1 << endl;
            return;
        }
        for (int i = m - 1; i >= 0; i--) {
            cout << mx[i];
        }
        cout << " " << res << endl;
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