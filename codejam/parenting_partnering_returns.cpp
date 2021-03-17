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
    int isFree(int start_time, int last_end_time, int last_start_time, int end_time) {
        return start_time >= last_end_time || last_start_time >= end_time;
    }

    void test_case(int test) {
        int n;
        cin >> n;
        vector<vector<int>> activities(n, vector<int>(3));

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            activities[i] = {x, y, i};
        }

        sort(activities.begin(), activities.end());

        int j_endtime = 0;
        int j_starttime = 0;
        int c_endtime = 0;
        int c_starttime = 0;
        string res = "";
        for (int i = 0; i < n; i++) {
            auto p = activities[i];
            if (isFree(p[0], j_endtime, j_starttime, p[1])) {
                res = res + "J";
                j_endtime = p[1];
                j_starttime = p[0];
            } else if (isFree(p[0], c_endtime, c_starttime, p[1])) {
                res += "C";
                c_endtime = p[1];
                c_starttime = p[0];
            } else {
                res = "IMPOSSIBLE";
                break;
            }
        }

        if (res == "IMPOSSIBLE") {
            cout << "Case #" << test << ": " << res << endl;
        } else {
            string resFinal(n, '0');
            for (int i = 0; i < n; i++) {
                auto v = activities[i];
                resFinal[v[2]] = res[i];
            }
            cout << "Case #" << test << ": " << resFinal << endl;
        }
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