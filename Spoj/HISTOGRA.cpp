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

void init(bool qwe = true) {
    test_cases = qwe;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct test_cases {
    int* lowestright;
    int* lowestleft;
    void lowest_left(int a[], int n) {
        stack<int> s;
        lowestleft = new int[n];
        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                lowestleft[i] = -1;
            } else {
                while (!s.empty() && a[s.top()] >= a[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    lowestleft[i] = -1;
                } else {
                    lowestleft[i] = s.top();
                }
            }
            s.push(i);
        }
    }

    void lowest_right(int a[], int n) {
        stack<int> s;
        lowestright = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                lowestright[i] = -1;
            } else {
                while (!s.empty() and a[s.top()] >= a[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    lowestright[i] = -1;
                } else {
                    lowestright[i] = s.top();
                }
            }

            s.push(i);
        }
    }

    void test_case(int n) {
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        lowest_left(a, n);
        lowest_right(a, n);

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            int L, R;
            L = lowestleft[i];
            R = lowestright[i];
            if (L == -1 && R == -1) {
                L = -1;
                R = n;
            } else if (R == -1) {
                R = n;
            }

            ans = max(ans, (R - L - 1) * a[i]);
        }
        cout << ans << endl;
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
    int n;
    while (cin >> n) {
        if (n == 0) break;
        struct test_cases o;
        o.test_case(n);
    }
    return 0;
};