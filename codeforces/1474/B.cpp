#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ump unordered_map
#define endl "\n"

vector<int> v;
const int MAXN = 1000005;
bool is_prime[MAXN];

void sieve() {
	memset(is_prime, true, sizeof is_prime);
	is_prime[0] = is_prime[1] = false;
	int i = 2;
	while(i*i <= MAXN) {
		if(is_prime[i]) {
			int k= i*i;
			while(k < MAXN) {
				is_prime[k] = false;
				k += i;
			}
		}
		i++;
	}

	for(int i = 2; i< MAXN; i++)
		if(is_prime[i])
			v.push_back(i);
}

void lego() {
	int d,x,y,cnt;
	cin >> d;
	// x = primes[lower_bound(primes.begin(), primes.end(), 1 + d) - primes.begin()];
	// y = primes[lower_bound(primes.begin(), primes.end(), x + d) - primes.begin()];
	// cout << x << " " << y << " " << x*y << endl;
	int res = 1;
	for(int i = 0; i < v.size(); i++) {
		if(v[i] - 1 >= d) {
			res*=(v[i]);
			break;
		}
	}

	for(int i = 0; i < v.size(); i++) {
		if(v[i] - res >= d) {
			res*=v[i];
			break;
		}
	}

	cout << res << endl;


}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sieve();
  int TT = 1;
  if (true)
    cin >> TT;
    
  while (TT--)
      lego();
}