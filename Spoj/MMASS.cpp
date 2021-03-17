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
    void test_case(int test) {
        string s;
        cin >> s;
        stack<int> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' and s[i] <= '9') {
                int k = st.top();
                st.pop();
                st.push(k * (s[i] - '0'));
            } else if (s[i] == '(') {
                st.push(-1);
            } else if (s[i] == ')') {
                int cur_sum = 0;
                while (st.top() != -1) {
                    cur_sum += st.top();
                    st.pop();
                }
                st.pop();
                st.push(cur_sum);
            } else {
                if (s[i] == 'C') {
                    st.push(12);
                } else if (s[i] == 'H') {
                    st.push(1);
                } else if (s[i] == 'O') {
                    st.push(16);
                }
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        cout << sum << endl;
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