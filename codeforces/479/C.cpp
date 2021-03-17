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

struct precompute {
    void compute() {
    }
};

struct test_cases {
    void test_case() {
        int n;
        cin >> n;
        vector<pair<int, int>> schedule;
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            cin >> p.first;
            cin >> p.second;
            schedule.push_back(p);
        }

        sort(schedule.begin(), schedule.end());

        // for (auto i : schedule) {
        //     cout << i.first << " " << i.second << endl;
        // }

        int curDay = min(schedule[0].first, schedule[0].second);

        for (int i = 1; i < schedule.size(); i++) {
            int mn = min(schedule[i].first, schedule[i].second);
            if (mn == curDay) {
                curDay = mn;
            } else if (mn > curDay) {
                curDay = mn;
            } else {
                curDay = max(schedule[i].first, schedule[i].second);
            }
        }
        cout << curDay << endl;
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