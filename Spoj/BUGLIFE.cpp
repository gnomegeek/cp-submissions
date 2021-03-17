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
    bool checkBipartite(ump<int, list<int>>& graph, int bugs) {
        ump<int, int> assigned;
        for (int i = 1; i <= bugs; i++) {
            assigned[i] = 0;
        }

        for (int src = 1; src <= bugs; src++) {
            if (assigned[src] == 0) {
                queue<int> Q;
                Q.push(src);
                assigned[src] = 1;
                int color = 1;
                while (!Q.empty()) {
                    int size = Q.size();
                    color = color == 1 ? 2 : 1;
                    for (int i = 0; i < size; i++) {
                        int cur_bug = Q.front();
                        Q.pop();

                        for (auto i : graph[cur_bug]) {
                            if (assigned[i] != 0) {
                                if (assigned[i] != color) {
                                    return false;
                                }
                            } else {
                                assigned[i] = color;
                                Q.push(i);
                            }
                        }
                    }
                }
            }
        }

        return true;
    }

    void test_case(int test) {
        int bugs, mates;
        cin >> bugs >> mates;
        ump<int, list<int>> graph;

        for (int i = 1; i <= bugs; i++) {
            graph[i] = {};
        }

        for (int i = 0; i < mates; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        cout << "Scenario #" << test << ":" << endl;
        if (!checkBipartite(graph, bugs)) {
            cout << "Suspicious bugs found!" << endl;
        } else {
            cout << "No suspicious bugs found!" << endl;
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