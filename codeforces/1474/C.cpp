#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ump unordered_map
#define endl "\n"

vector<pair<int, int>> check(int x, multiset<int> l) {
	vector<pair<int, int>> res;
	while(!l.empty()) {
		int num1 = *(--l.end());
		l.erase(--l.end());
		int num2 = x - num1;
		auto itr = l.find(num2);
		if(itr != l.end()) {
			res.push_back({num1, num2});
			x = max(num1, num2);
			l.erase(itr);
		} else {
			return {};
		}
	}

	return res;

}

void print(vector<pair<int, int>> v) {
	for(auto i: v)
		cout << i.first << " " << i.second << endl;
}

void lego() {
	int n,x,y,cnt;
	cin >> n;
	multiset<int> l, m, k;
	for(int i = 0; i < 2*n; i++) {
		cin >> x;

		l.insert(x);
		m.insert(x);
		k.insert(x);
	}

	x = *(--l.end());

	for(auto i = k.begin(); i!= (--k.end()); i++) {
		int num = *i;
		vector<pair<int, int>> v = check(num + x, l);
		// cout << *i << " - > " <<  endl;
		// print(v);
		if(v.size() != 0) {
			cout << "YES" << endl;
			cout << x + num<< endl;
			print(v);
			return;
		}
		l = k;
	}

	cout << "NO" << endl;
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