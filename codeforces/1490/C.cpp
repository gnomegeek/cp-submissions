#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ump unordered_map
#define endl "\n"

void lego() {
	int n,x,cnt;
	cin >> x;
	int y = pow(sqrt(x), 2/3.0);

	int left = 1; int right = y + 1;
	while(left <= right) {
		int res = left*left*left + right*right*right;
		if(res == x) {
			cout << "yes" << endl;
			return;
		}

		if(res < x) {
			left ++;
		} else {
			right--;
		}
	}


	cout << "no" << endl;
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