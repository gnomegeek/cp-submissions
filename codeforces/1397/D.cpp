#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int sum = 0, a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
 
		sort(a, a + n);
		if(a[n-1] > sum - a[n-1]) {
			cout << "T" << endl;
		} else if(sum % 2 == 0) {
			cout << "HL" << endl;
		} else {
			cout << "T" << endl;
		}
	}
	return 0;
}