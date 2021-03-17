#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ump unordered_map
#define endl "\n"

void lego() {
	int n,x,y,cnt=0;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	sort(a, a+n);
	
	cnt= 1;
	for(int i = 1; i<= n; i++) {
		if(a[i] == a[i-1]) cnt++;
		else {
			break;
		}
	}

	cout << n-cnt << endl;
	
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