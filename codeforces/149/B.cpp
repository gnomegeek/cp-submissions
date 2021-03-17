#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
#define fo(i, j, k, in) for (int i = j; i < k; i += in)
#define inputArray(a, n) \
    for (int i = 0; i < n; i++) cin >> a[i];
#define printArray(a, n) \
    for (int i = 0; i < n; i++) cout << a[i] << endl;
#define Sld(t) scanf("%ld", &t)
#define scc(t) scanf("%c", &t)
#define sf(t) scanf("%f", &t)
#define slf(t) scanf("%lf", &t)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define clr(val, val1) memset(val, val1, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int valueOf(char c) {
    if (c <= '9' && c >= '0') return (int)(c - '0');
    return int(c - 'A') + 10;
}

int solve(string hrs, string min) {
    // Max of hrs & min
    int mx = INT_MIN;
    for (int i = 0; i < hrs.length(); i++) {
        int k = valueOf(hrs[i]);
        mx = max(mx, k);
    }
    for (int i = 0; i < min.length(); i++) {
        int k = valueOf(min[i]);
        mx = max(mx, k);
    }

    return mx + 1;
}

int convertToSystem(int sys, string s) {
    int res = 0;
    int c = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        int num = valueOf(s[i]);
        res = res + pow(sys, c) * num;
        c++;
    }
    return res;
}

int main() {
    FastIO;
    string s;
    cin >> s;
    string hrs, min;
    int flag = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ':') flag = 1;
        if (!flag)
            hrs = hrs + s[i];
        else
            min = min + s[i];
    }
    min.erase(0, 1);
    vector<int> v;
    // Hrs & Min
    int startSystem = solve(hrs, min);
    int infinite = 0;
    int oldhrsval = convertToSystem(startSystem, hrs);
    int oldminval = convertToSystem(startSystem, min);
    if (oldhrsval < 24) {
        if (oldminval < 60) {
            v.push_back(startSystem);
        }
    }
    for (int i = startSystem + 1; true; i++) {
        int hrsval = convertToSystem(i, hrs);
        int minval = convertToSystem(i, min);
        if (hrsval < 24) {
            if (minval < 60) {
                v.push_back(i);
            } else {
                break;
            }
        } else {
            break;
        }
        if (i == startSystem + 1 && oldhrsval == hrsval && oldminval == minval) {
            infinite = 1;
            cout << -1;
            break;
        }
    }

    if (!infinite) {
        if (v.size() == 0)
            cout << 0;
        else {
            for (int i : v) {
                cout << i << " ";
            }
        }
    }

    return 0;
}