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
    void compute() {
    }
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
        vector<int> v(n), a(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            a[i] = i + 1;
        }

        if (n == 1) {
            cout << a[0] << " " << a[0] << endl;
            cout << 0 << endl;
            cout << a[0] << " " << a[0] << endl;
            cout << 0 << endl;
            cout << a[0] << " " << a[0] << endl;
            cout << -1 * v[0] << endl;
            return;
        }
        if (n == 2) {
            cout << a[0] << " " << a[1] << endl;
            cout << 0 << " " << 0 << endl;
            cout << a[0] << " " << a[0] << endl;
            cout << -1 * v[0] << endl;
            cout << a[1] << " " << a[1] << endl;
            cout << -1 * v[1] << endl;
            return;
        }

        if (n == 3) {
            cout << a[0] << " " << a[0] << endl;
            cout << -1 * v[0] << endl;
            cout << a[1] << " " << a[1] << endl;
            cout << -1 * v[1] << endl;
            cout << a[2] << " " << a[2] << endl;
            cout << -1 * v[2] << endl;
            return;
        }

        // step1
        cout << a[1 - 1] << " " << a[n - 1 - 1] << endl;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] % n == 0) {
                cout << 0 << " ";
            } else {
                int toBeAdded = (n - 1) * v[i];
                cout << toBeAdded << " ";
                v[i] += toBeAdded;
            }
        }
        cout << endl;

        // step2
        cout << a[n - 1] << " " << a[n - 1] << endl;
        if (v[n - 1] % n == 0) {
            cout << 0;
        } else {
            cout << (n - 1) * v[n - 1];
            v[n - 1] += (n - 1) * v[n - 1];
        }
        cout << endl;

        // step3
        cout << a[1 - 1] << " " << a[n - 1] << endl;
        for (int i = 0; i < n; i++) {
            cout << -1 * v[i] << " ";
        }
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