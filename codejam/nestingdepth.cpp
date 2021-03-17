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
}

struct precompute {
    void compute() {
    }
};

struct test_cases {
    void test_case(int test) {
        string s;
        cin >> s;
        int p_open = 0;
        int n = s.length();
        string res = "";
        for (int i = 0; i < n; i++) {
            int dig = s[i] - 48;
            if (p_open == dig) {
            } else if (p_open < dig) {
                for (int j = p_open; p_open != dig; j++) {
                    res += "(";
                    p_open++;
                }
            } else {
                for (int j = p_open; p_open != dig; j--) {
                    res += ")";
                    p_open--;
                }
            }
            res += s[i];
        }

        while (p_open) {
            p_open--;
            res += ")";
        }

        cout << "Case #" << test << ": " << res << endl;
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