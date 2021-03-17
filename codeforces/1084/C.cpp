#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define int long long
#define ump unordered_map
#define endl "\n"
#define mod 1000000007

void OJ() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

template <typename T>
bool is_sorted(T a[], int n) {
    if(n == 1) return true;
    for(int i = 1; i <n; i++)
        if(a[i] < a[i-1]) return false;
    return true;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b)/(gcd(a, b));
}

void lego() {
    string s, s1 = "";
    cin >> s;
    int res = 1, cnt = 0;
    for(int i = 0; i != s.length(); i++) {
        if(s[i] != 'a' and s[i] != 'b') continue; 
        else s1 += s[i];
    }
    cnt = 0;
    for(int i = 0; i<s1.length(); i++) {
        if(s1[i] == 'a') cnt ++;
        else {
            res = ((res%mod)*((1+cnt)%mod))%mod;
            cnt = 0;
        }
    }
    res = ((res%mod)*((1+cnt)%mod))%mod;
    cnt = 0;
    cout <<--res<< endl;
    return;
}

signed main() {
    OJ();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    if (false)
        cin >> tt;
    while (tt--) lego();

    return 0;
}