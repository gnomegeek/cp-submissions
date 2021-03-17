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
    void test_case(int n) {
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        stack<int> st;
        int next = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == next) {
                next++;
            } else {
                if (st.empty()) {
                    st.push(a[i]);
                } else {
                    if (st.top() == next) {
                        i--;
                        st.pop();
                        next++;
                    } else {
                        st.push(a[i]);
                    }
                }
            }
        }

        while (!st.empty() and st.top() == next) {
            st.pop();
            next++;
        }

        if (st.empty()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
};

int32_t main() {
    init(false);
    int tc;
    if (test_cases) {
        cin >> tc;
    } else {
        tc = INT_MAX;
    }
    for (int i = 0; i < tc; i++) {
        int k;
        cin >> k;
        struct test_cases o;
        if (k == 0) return 0;
        o.test_case(k);
    }
    return 0;
};