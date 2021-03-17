#include <bits/stdc++.h>
using namespace std;

// #define inf INT_MAX
// #define int long long
// #define ump unordered_map
// #define endl "\n"
// #define mod 10000000

void OJ() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool bs(vector<int>& a, int k) {
    int left = 0, right = a.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == k) return true;
        if (a[mid] < k) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

void lego() {
    int n, cnt = 0, lol = 0;
    cin >> n;
    int a[n + 1], sum[n + 1];

    for (int i = 1; i <= n; i++) cin >> a[i];

    sum[0] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];

    // sort(diff.begin(), diff.end());

    int note[n+1];
    for(int i = 0; i <= n; i++) note[i] = -1;

    for (int i = 1; i <= n; i++) {
        int req = a[i];
        // bool found = bs(diff, req);
        // if (found) cnt ++;

        int left = 0, right = left + 2;

        if(note[req] == 1) {
            cnt++;
            continue;
        }

        if(note[req] == 2) {
            continue;
        }

        note[req] = 2;

        while (left != n + 1 and right != n + 1) {
            if (sum[right] - sum[left] == req) {
                if (right - left > 1) {
                    cnt++;
                    note[req] = 1;
                    break;
                }
                else {
                    left++;
                    right++;
                }
            } else if (sum[right] - sum[left] < req) {
                right++;
            } else {
                left ++;
            }
        }

    }

    cout << cnt << endl;
}

int main() {
    OJ();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    if (true)
        cin >> tt;
    while (tt--) lego();

    return 0;
}