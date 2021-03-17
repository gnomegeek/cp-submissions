#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
#define inputArray(a, n) \
    for (int i = 0; i < n; i++) cin >> a[i];
#define printArray(a, n) \
    for (int i = 0; i < n; i++) cout << a[i] << endl;
typedef pair<int, int> pii;
#define endl "\n"
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define int long long
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define clr(val, val1) memset(val, val1, sizeof(val))

void __init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> primes;
bitset<10000> b;
void seive() {
    b.set();
    b[0] = 0;
    b[1] = 0;
    for (int i = 2; i * i <= 10000; i++) {
        if (b[i]) {
            int k = i * i;
            while (k <= 10000) {
                b[k] = 0;
                k = k + i;
            }
        }
    }
    for (int i = 1000; i < 10000; i++) {
        if (b[i] == 1) {
            primes.PB(i);
        }
    }
}

int matchDig(int a, int b) {
    int res = 0;
    while (a != 0 && b != 0) {
        int aD = a % 10;
        int bD = b % 10;
        if (aD == bD) res++;
        a /= 10;
        b /= 10;
    }
    return res;
}

int32_t main() {
    __init();
    seive();

    // Prepare AdjList;
    unordered_map<int, list<int>> primePath;
    for (int i = 1001; i <= 9999; i++) {
        if (b[i]) {
            for (auto j : primes) {
                if (matchDig(j, i) == 3) {
                    primePath[i].PB(j);
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int a, c;
        cin >> a >> c;

        // Basic BFS
        int ans, paths = 0;
        unordered_map<int, bool> visited;
        for (int i = 1000; i <= 9999; i++) {
            if (b[i]) {
                visited[i] = false;
            }
        }
        queue<int> Q;
        Q.push(a);
        visited[a] = true;
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                int curr = Q.front();
                Q.pop();
                if (curr == c) {
                    ans = paths;
                    while (!Q.empty()) Q.pop();
                    break;
                } else {
                    for (auto j : primePath[curr]) {
                        if (!visited[j]) {
                            visited[j] = true;
                            Q.push(j);
                        }
                    }
                }
            }
            paths++;
        }
        cout << ans << endl;
    }

    return 0;
}