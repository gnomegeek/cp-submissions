#include <math.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using ld = long double;
using namespace std;

// #define int long long
#define inf INT_MAX
#define umap unordered_map<int, int>
#define endl "\n"
#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define mid(s, e) ((s + (e - s) / 2))
#define mod 1000000007

int main() {
    int n, target;
    cin >> n >> target;

    int price[n], pages[n];

    int dp[n + 1][target + 1];

    for (int i = 0; i < n; i++) cin >> price[i];

    for (int i = 0; i < n; i++) cin >> pages[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = (i == 1) ? 0 : dp[i - 1][j];
            if (j - price[i - 1] >= 0) {
                dp[i][j] = max(
                    dp[i][j], pages[i - 1] +
                                  ((i == 1) ? 0 : dp[i - 1][j - price[i - 1]]));
            }
        }
    }

    cout << dp[n][target] << endl;
    return (int)0;
}