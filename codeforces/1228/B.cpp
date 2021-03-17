#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ump unordered_map
#define endl "\n"
#define mod 1000000007

int solve(int a, int n) {

	if(n == 1) return a % mod;
	if(n == 0) return 1;

	if(n%2==0)
		return (solve((a%mod)*(a%mod)%mod, n/2))%mod;

	else
		return ((a%mod)*(solve(a,n-1)%mod))%mod;
}

void lego() {
	int n,h,w,cnt = 0;
	cin >> h >> w;
	int row[h], col[w];
	short a[h][w];
	memset(a, -1, sizeof(a));
	for(int i = 0; i < h; i++)
		cin >> row[i];

	for(int i = 0; i < w; i++)
		cin >> col[i];

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < row[i]; j++) {
			a[i][j] = 1;
		}
		if(row[i] < w)
			a[i][row[i]] = 0;
	}

	for(int j = 0; j < w; j++) {
		for(int i = 0; i < col[j]; i++) {
			if(a[i][j] == 0) {
				cout << 0 << endl;
				return;
			}
			a[i][j] = 1;
		}

		if(col[j] < h and a[col[j]][j] == 1) {
			cout << 0 << endl;
			return;
		}

		if(col[j] < h)
			a[col[j]][j] = 0;
	}

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(a[i][j] == -1) cnt++;
		}
	}

	cout << solve(2, cnt)%mod << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TT = 1;
  if (false)
    cin >> TT;
    
  while (TT--)
      lego();
}