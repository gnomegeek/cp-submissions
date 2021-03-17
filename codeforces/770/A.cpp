/*
    Author: Vatsal Agarwal
    Birla Institute of Technology and Sciences, Pilani, Goa Campus

    Make it work, make it right, make it fast.
*/

#include <bits/stdc++.h>
using namespace std;
typedef int itn;
#define int long long
#define inf INT_MAX
#define umap unordered_map<int, int>
#define endl "\n"
#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define mid(s, e) ((s + (e - s) / 2))
#define mod 1000000007
#define scArray(a, b) \
    for (int i = 0; i < b; i++) cin >> a[i]

// assign 1 to tt for testcases
int TT = 0;

void lego() {
    int n, k;
    cin >> n >> k;
    string pass = "";
    int i = 1, j = 0;
    while (i <= n) {
        if (j == 26 || j == k) j = 0;
        pass += char(j + 97);

        j++;
        i++;
    }

    cout << pass << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (TT) {
        cin >> TT;
        while (TT--) {
            lego();
        }
    } else
        lego();
}