#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ump unordered_map
#define endl "\n"

void lego() {
	int n,x,y,cnt;
	cin >> n;
	string s;
	cin >> s;

	int last;
	string res = "1";

	if(s[0] == '0') last = 1;
	else last = 2;

	for(int i = 1; i < n; i++) {
		char ch;

		if(last == 0) {
			// res = '1' + res;
			ch = '1';
		}

		if(last == 1) {
			if(s[i] == '1') {
				// res = '1' + res;
				ch = '1';
			} else {
				// res = '0' + res;
				ch = '0';
			}
		}

		if(last == 2) {
			if(s[i] == '1') {
				// res = '0' + res;
				ch = '0';
			} else {
				// res = '0' + res;
				ch = '1';
			}
		}

		res = res + ch;
		last = ch - '0' + s[i] -'0';
	}

	cout << res << endl;
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