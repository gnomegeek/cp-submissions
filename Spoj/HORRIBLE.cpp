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

int lazy[500000];

void buildTree(int* tree, int a[], int s, int e, int idx) {
    if (s == e) {
        tree[idx] = a[s];
        return;
    }

    int mid = (s + e) / 2;
    buildTree(tree, a, s, mid, 2 * idx);
    buildTree(tree, a, mid + 1, e, 2 * idx + 1);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    return;
}

void updateRange(int* tree, int s, int e, int qs, int qe, int val, int idx) {
    if (lazy[idx] != 0) {
        tree[idx] += lazy[idx] * (e - s + 1);
        if (s != e) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if (qe < s || qs > e) {
        return;
    }

    if (qs <= s && qe >= e) {
        tree[idx] += val * (e - s + 1);
        if (s != e) {
            lazy[2 * idx] += val;
            lazy[2 * idx + 1] += val;
        }
        return;
    }
    int mid = (s + e) / 2;
    updateRange(tree, s, mid, qs, qe, val, 2 * idx);
    updateRange(tree, mid + 1, e, qs, qe, val, 2 * idx + 1);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    return;
}

int query(int* tree, int s, int e, int qs, int qe, int idx) {
    if (lazy[idx] != 0) {
        tree[idx] += lazy[idx] * (e - s + 1);
        if (s != e) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if (qe < s || qs > e) {
        return INT_MIN;
    }

    if (qs <= s && qe >= e) {
        return tree[idx];
    }

    int mid = (s + e) / 2;
    int x = query(tree, s, mid, qs, qe, 2 * idx);
    int y = query(tree, mid + 1, e, qs, qe, 2 * idx + 1);

    if (x == INT_MIN) {
        return y;
    }

    if (y == INT_MIN) {
        return x;
    }

    return x + y;
}

int32_t main() {
    __init();
    int t;
    cin >> t;
    while (t--) {
        memset(lazy, 0, sizeof(lazy));
        int n, c;
        cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = 0;
        }
        int* tree = new int[4 * n + 1];
        buildTree(tree, a, 0, n - 1, 1);

        for (int i = 0; i < c; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                int p, q;
                cin >> p >> q;
                cout << query(tree, 0, n - 1, p - 1, q - 1, 1) << endl;
            } else {
                int p, q, val;
                cin >> p >> q >> val;
                updateRange(tree, 0, n - 1, p - 1, q - 1, val, 1);
            }
        }
        delete[] tree;
    }
    return 0;
}