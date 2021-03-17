#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define int long long
#define ump unordered_map
#define endl "\n"
#define mod 10000000

void OJ() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

template <typename T>
bool is_sorted(T a[], int n) {
    if(n == 1) return true;
    for(int i = 1; i <n; i++)
        if(a[i] < a[i-1]) return false;
    return true;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b)/(gcd(a, b));
}

const int MAXN = 1e5 + 5;

void lego() {
    int a[MAXN] = {0}, cnt[MAXN] = {0};
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] ++;
        cnt[a[x]] ++;
    }

    int q;
    cin >> q;
    while(q--) {
        char ch;
        int k;cin >> ch;
        cin >> k;

        if(ch == '+') {
            a[k]++;
            cnt[a[k]] ++;
        }

        if(ch == '-') {
            cnt[a[k]] --;
            a[k]--;
        }

        if(cnt[8] > 0 || cnt[4] >= 2 || (cnt[6] > 0 and cnt[2] > 1) || (cnt[4] >= 1 and cnt[2] > 2)) {
            cout << "yes";
        } else {
            cout << "no";
        }
        cout << endl;
    }

}

signed main() {
    OJ();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    if (false)
        cin >> tt;
    while (tt--) lego();

    return 0;
}