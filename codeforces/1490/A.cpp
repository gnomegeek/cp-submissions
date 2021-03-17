#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ump unordered_map
#define endl "\n"

void lego() {
	int n,x,y,cnt = 0;
	cin >> n;
		int a[n];

	for(int i = 0; i  <n; i++) cin >> a[i];
	for(int i = 0; i < n-1; i++) {
		int small = min(a[i], a[i+1]);
		int big = max(a[i],a[i+1]);

		if((big*1.0)/small <= 2) continue; 

		x = small*2;
		while((big*1.0)/small > 2) {
			// cout << x << " ";
			cnt++;
			small = x;
			x =small *  2;

		}
	}

	cout << cnt << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TT = 1;
  if (true)
    cin >> TT;
    
  while (TT--)
      lego();
}