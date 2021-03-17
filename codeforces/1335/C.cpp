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
    bool is_possible(int mid, ump<int, int> &mp) {
        int unique = 0;
        int types_of_multiples = 0;
        int max_repeated = 0;
        for (auto i : mp) {
            pair<int, int> p = i;
            if (i.second > 1) {
                max_repeated = max(max_repeated, i.second);
                types_of_multiples++;
            } else {
                unique++;
            }

            if (((unique + types_of_multiples - 1) >= mid and max_repeated >= mid) || (max_repeated - 1 >= mid and unique + types_of_multiples >= mid)) return true;
        }
        // cout << unique << " " << types_of_multiples << " " << max_repeated << " " << mid << endl;
        return false;
    }

    void test_case(int test) {
        int n;
        cin >> n;

        ump<int, int> mp;
        int not_all_unique = 0;
        int a[n];
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (mp.count(x)) {
                not_all_unique = 1;
                mp[x]++;
            } else {
                mp[x] = 1;
            }
        }
        // cout << "TEST CASE : " << test << endl;
        // for (auto i : mp) {
        //     cout << i.first << " " << i.second << endl;
        // }

        if (n == 1) {
            cout << 0 << endl;
            return;
        }

        if (n == 2) {
            cout << 1 << endl;
            return;
        }

        if (!not_all_unique) {
            cout << 1 << endl;
            return;
        }

        int s = 0;
        int e = n / 2;
        int ans;
        while (s <= e) {
            int mid = mid(s, e);
            if (is_possible(mid, mp)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        cout << ans << endl;
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