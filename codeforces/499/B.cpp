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

void init(bool k) {
    test_cases = k;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct test_cases {
    void test_case() {
        int n, m;
        cin >> n >> m;
        unordered_map<string, string> mp;
        for (int i = 0; i < m; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            string a, b;
            if (s1.length() < s2.length()) {
                a = s1;
                b = s2;
            } else if (s1.length() > s2.length()) {
                a = s2;
                b = s1;
            } else {
                a = s1;
                b = s1;
            }
            mp[b] = a;
        }

        for (int i = 0; i < n; i++) {
            string k;
            cin >> k;
            if (mp.count(k)) {
                cout << mp[k] << " ";
            } else {
                cout << k << " ";
            }
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
    for (int i = 0; i < tc; i++) {
        struct test_cases o;
        o.test_case();
    }
    return 0;
};