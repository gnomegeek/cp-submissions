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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct precompute {
    void compute() {
    }
};

struct test_cases {
    void test_case() {
        int n;
        cin >> n;
        ump<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (mp.count(x))
                mp[x]++;
            else
                mp[x] = 1;
        }

        if (mp.count(7) || mp.count(5)) {
            cout << -1 << endl;
            return;
        }
        vector<vector<int>> res;

        for (int i = 1; i < 7; i++) {
            for (int j = i + 1; j < 7; j++) {
                for (int k = j + 1; k < 7; k++) {
                    if (k % j == 0 && j % i == 0) {
                        while (mp[i] != 0 && mp[j] != 0 && mp[k] != 0) {
                            res.pb({i, j, k});
                            mp[i]--;
                            mp[j]--;
                            mp[k]--;
                        }
                    }
                }
            }
        }

        if (res.size() == (n / 3)) {
            for (auto i : res) {
                for (auto j : i) {
                    cout << j << " ";
                }
                cout << endl;
            }

        } else
            cout << -1 << endl;
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
        o.test_case();
    }
    return 0;
};