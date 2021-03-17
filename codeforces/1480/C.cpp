#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define int long long
#define ump unordered_map
#define endl "\n"
#define mod 1000000007

void OJ() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}

int a[100010] = {0};

void lego() {
    int n;
    cin >> n;
    int left = 1, right = n;
    a[0] = inf;
    a[n + 1] = inf;

    while (left < right) {
        int mid = (left + right) / 2;

        if (a[mid - 1] == 0) {
            cout << "? " << mid - 1 << endl
                 << flush;
            cin >> a[mid - 1];
        }
        if (a[mid] == 0) {
            cout << "? " << mid << endl
                 << flush;
            cin >> a[mid];
        }
        if (a[mid + 1] == 0) {
            cout << "? " << mid + 1 << endl
                 << flush;
            cin >> a[mid + 1];
        }

        if (a[mid] < a[mid + 1] and a[mid] < a[mid - 1]) {
            cout << "! " << mid << endl
                 << flush;
            return;
        } else if (a[mid] > a[mid + 1]) {
            left = mid + 1;
        } else if (a[mid] > a[mid - 1]) {
            right = mid - 1;
        }
    }

    if (a[left - 1] == 0) {
        cout << "? " << left - 1 << endl
             << flush;
        cin >> a[left - 1];
    }
    if (a[right + 1] == 0) {
        cout << "? " << right + 1 << endl
             << flush;
        cin >> a[right + 1];
    }
    if (a[left] < a[left - 1] and a[left] < a[left + 1]) {
        cout << "! " << left << endl
             << flush;
        return;
    }

    cout << "! " << right << endl
         << flush;
    return;
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