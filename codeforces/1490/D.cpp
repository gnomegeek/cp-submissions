#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ump unordered_map
#define endl "\n"
#define inf INT_MAX

int depth[101];
int a[101];

void f(int a[], int s, int e, int d) {
	
	if(s > e) return;

	int maxi = -inf, idx = -1;
	for(int i = s; i <= e; i++) {
		if(a[i] > maxi) {
			maxi = a[i];
			idx = i;
		}
	}

	depth[idx] = d;

	f(a, idx+1,e,d+1);
	f(a, s,idx-1, d+1); 


}

void lego() {
	int n,x,y,cnt;
	cin >> n;
	memset(depth, -1, sizeof(depth));
	for(int i = 0; i < n; i++) cin >> a[i];

	f(a, 0, n-1, 0);

	for(int i = 0; i < n; i++) cout << depth[i] << " ";

	cout << endl;

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