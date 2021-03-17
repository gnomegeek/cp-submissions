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
        string s;
        cin >> s;
        int n = s.length();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int c = 0;
                for (int j = i; s[j] == '1'; j++) {
                    c++;
                }
                v.pb(c);
                i += c;
            }
        }

        // for (auto i : v) cout << i << " ";
        // cout << endl;

        sort(v.begin(), v.end());
        int size = v.size();
        int res = 0;
        for (int i = size - 1; i >= 0; i -= 2) {
            res += v[i];
        }

        cout << res << endl;
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
    struct precompute l;
    l.compute();
    for (int i = 0; i < tc; i++) {
        struct test_cases o;
        o.test_case(i + 1);
    }
    return 0;
};