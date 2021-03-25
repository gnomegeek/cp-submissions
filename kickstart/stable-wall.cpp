#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

const int LINF = 1e18;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const int MOD2 = 998244353;

int gcd(int a, int b), lcm(int a, int b), expo(int e, int n);

bool cases = true;

bool helper(map<char, set<char> >& graph, int i, bool visited[],
            bool cur_path[]) {
    bool res = false;
    cur_path[i] = true;
    visited[i] = true;
    for (auto j : graph[i + 'A']) {
        if (cur_path[j - 'A']) {
            return true;
        } else if (!visited[j - 'A']) {
            res = res || helper(graph, j - 'A', visited, cur_path);
            if (res) return res;
        }
    }
    cur_path[i] = false;
    return false;
}

bool cycle(map<char, set<char> >& graph) {
    bool visited[26] = {0};
    bool res = false;
    bool cur_path[26] = {0};
    for (int i = 0; i < 26; i++) {
        if (!visited[i]) {
            res = res || helper(graph, i, visited, cur_path);
            if (res) return res;
        } else
            memset(cur_path, false, sizeof cur_path);
    }
    return false;
}

void dfs(int i, vector<char>& toposort, map<char, set<char> >& graph,
         bool visited[]) {
    char ch = i + 'A';
    visited[i] = true;

    for (auto j : graph[ch])
        if (!visited[j - 'A']) dfs(j - 'A', toposort, graph, visited);

    toposort.pb(ch);
}

void letsGO(int test) {
    int r, c;
    cin >> r >> c;
    cout << "Case #" << test << ": ";
    set<char> all;
    char mat[r + 1][c + 1];
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) cin >> mat[i][j], all.insert(mat[i][j]);

    map<char, set<char> > graph;
    for (int i = 1; i <= r - 1; i++)
        for (int j = 1; j <= c; j++)
            if (mat[i][j] != mat[i + 1][j])
                graph[mat[i][j]].insert(mat[i + 1][j]);

    if (cycle(graph)) {
        cout << -1 << endl;
    } else {
        bool visited[26] = {false};
        vector<char> toposort;
        for (int i = 0; i < 26; i++)
            if (!visited[i] and all.find(i + 'A') != all.end())
                dfs(i, toposort, graph, visited);

        for (char i : toposort) cout << i;
        cout << endl;
    }
}

void speeeeeeeeeed() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int expo(int e, int n) {
    return n ? n & 1 ? e * expo(e, --n) : expo(e * e, n / 2) : 1;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

signed main() {
    speeeeeeeeeed();
    cout << fixed << setprecision(10);
    int TT = 1, cnt = 0;
    if (cases) cin >> TT;
    while (TT--) letsGO(++cnt);
}