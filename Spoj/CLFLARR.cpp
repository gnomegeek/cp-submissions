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

int lazy[1000000] = {0};

void buildTree(int* a, int* tree, int s, int e, int idx) {
    if (s == e) {
        tree[idx] = 0;
        return;
    }
    int mid = (s + e) / 2;
    buildTree(a, tree, s, mid, 2 * idx);
    buildTree(a, tree, mid + 1, e, 2 * idx + 1);
    tree[idx] = 0;
    return;
}

void updateRangeLazy(int* tree, int qs, int qe, int val, int idx, int s, int e) {
    // Resolve Lazy
    if (lazy[idx] != 0) {
        tree[idx] = lazy[idx];
        if (s != e) {
            lazy[2 * idx] = lazy[idx];
            lazy[2 * idx + 1] = lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (qs > e || qe < s) {
        // No overlap
        return;
    }

    if (qs <= s && qe >= e) {
        // complete overlap
        tree[idx] = val;
        if (s != e) {
            lazy[2 * idx] = val;
            lazy[2 * idx + 1] = val;
        }
        return;
    }

    // partial overlap
    int mid = (s + e) / 2;
    updateRangeLazy(tree, qs, qe, val, 2 * idx, s, mid);
    updateRangeLazy(tree, qs, qe, val, 2 * idx + 1, mid + 1, e);
    return;
}

void printRes(int* tree, int idx, int s, int e) {
    // Resolve Lazy
    if (lazy[idx] != 0) {
        tree[idx] = lazy[idx];
        if (s != e) {
            lazy[2 * idx] = lazy[idx];
            lazy[2 * idx + 1] = lazy[idx];
        }
        lazy[idx] = 0;
    }

    // Base Case
    if (s == e) {
        cout << tree[idx] << endl;
        return;
    }

    // Recursive Case
    int mid = (s + e) / 2;
    printRes(tree, 2 * idx, s, mid);
    printRes(tree, 2 * idx + 1, mid + 1, e);
    return;
}

int32_t main() {
    __init();
    int n, q;
    cin >> n >> q;

    int a[n] = {0};
    int tree[4 * n + 1] = {0};
    buildTree(a, tree, 0, n - 1, 1);

    for (int i = 0; i < q; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        updateRangeLazy(tree, l - 1, r - 1, c, 1, 0, n - 1);
    }

    printRes(tree, 1, 0, n - 1);
    return 0;
}