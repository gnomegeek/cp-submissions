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
    void test_case(int cnt, string test) {
        stack<char> st;
        int n = test.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char ch = test[i];
            if (ch == '{') {
                st.push('{');
            } else {
                if (st.empty()) {
                    ans++;
                    st.push('{');
                } else {
                    st.pop();
                }
            }
        }
        cout << cnt << ". ";
        if (st.empty()) {
            cout << ans << endl;
        } else {
            cout << ans + st.size() / 2 << endl;
        }
    }
};

int32_t main() {
    init(false);
    string tc;
    if (test_cases) {
        cin >> tc;
    }
    int cnt = 0;
    for (int i = 0; i == 0; i = 0) {
        cin >> tc;
        cnt++;
        if (tc[0] == '-') {
            return 0;
        }
        struct test_cases o;
        o.test_case(cnt, tc);
    }
    return 0;
};