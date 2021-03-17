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

void init(bool k) {
    test_cases = k;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct test_cases {
    void print(int a[], int n) {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
    }
    void test_case(int test) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int idx1, idx2;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                idx1 = i;
                int just = idx1 + 1;
                for (int j = i; j < n; j++) {
                    if (a[j] > a[idx1] and a[just] > a[j]) {
                        just = j;
                    }
                }
                swap(a[just], a[idx1]);

                if (idx1 < n - 1) {
                    sort(a + idx1 + 1, a + n);
                }
                print(a, n);
                return;
            }
        }

        cout << -1 << endl;
        return;
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