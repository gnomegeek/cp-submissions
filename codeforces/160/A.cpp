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
	int n;
	cin >> n;
	int a[n], sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	int half = sum / 2 + 1;

	sort(a, a + n);
	int csum = 0, cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		csum += a[i];
		cnt++;
		if (csum >= half) {
			cout << n - i << endl;
			return;
		}
	}
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