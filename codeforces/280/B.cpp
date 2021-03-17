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
    void prepare_left(int *great_left, int n, int *a) {
        stack<int> st;

        // great_left
        great_left[0] = -1;
        st.push(a[0]);
        for (int i = 1; i < n; i++) {
            while (!st.empty() and st.top() < a[i]) {
                st.pop();
            }

            if (st.empty()) {
                great_left[i] = -1;
            } else {
                great_left[i] = st.top();
            }
            st.push(a[i]);
        }
    }

    void
    prepare_right(int *great_right, int n, int *a) {
        stack<int> st;

        great_right[n - 1] = -1;
        st.push(a[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() and st.top() < a[i]) {
                st.pop();
            }

            if (st.empty()) {
                great_right[i] = -1;
            } else {
                great_right[i] = st.top();
            }
            st.push(a[i]);
        }
    }

    void test_case(int test) {
        int n;
        cin >> n;
        int a[n];
        int great_left[n];
        int great_right[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, a[i] ^ a[i + 1]);
        }

        prepare_left(great_left, n, a);
        prepare_right(great_right, n, a);

        for (int i = 0; i < n; i++) {
            int left = great_left[i];
            int right = great_right[i];
            if (left != -1) {
                ans = max(ans, left ^ a[i]);
            }
            if (right != -1) {
                ans = max(ans, right ^ a[i]);
            }
            if (left != -1 and right != -1) {
                ans = max(ans, left ^ right);
            }
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
    for (int i = 0; i < tc; i++) {
        struct test_cases o;
        o.test_case(i + 1);
    }
    return 0;
};