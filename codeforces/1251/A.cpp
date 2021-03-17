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
        // 0 -> good, 1 -> bad, 2 -> not checked
        int good[26];
        for (int i = 0; i < 26; i++) good[i] = 2;

        for (int i = 0; i < n; i++) {
            int cnt = 0, j = i, k = (int)(s[i] - 'a');
            if (good[k] == 0) continue;
            while (s[j] == s[i] and j < n) {
                cnt++;
                j++;
            }
            good[k] = (cnt & 1) ? 0 : 1;
            i = j - 1;
        }

        for (int i = 0; i < 26; i++) {
            if (good[i] == 0) {
                cout << (char)('a' + i);
            }
        }

        cout << endl;
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