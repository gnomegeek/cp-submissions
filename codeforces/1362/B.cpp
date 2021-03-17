#include<bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
#define fo(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define Sld(t) scanf("%ld",&t)
#define scc(t) scanf("%c",&t)
#define sf(t) scanf("%f",&t)
#define slf(t) scanf("%lf",&t)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define clr(val, val1) memset(val,val1,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool isEqual(set <int> a, set <int> b) {
    for (auto it1 = a.begin(), it2 = b.begin(); it1 != a.end() ; it1 ++, it2 ++){
        if(*it1 != *it2) {
            return false;
        }
    }
    return true;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set <int> s;
        for(int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        set <int> xored;
        int k;
        for(k = 1; k < 1025; k ++) {
            xored.clear();
            for(auto x: s) {
                xored.insert(k ^ x);
            }
            if(isEqual(xored, s)) {
                cout << k << endl;
                k = 1029;
            }
        }
        if(k != 1030) {
            cout << -1 << endl;
        }

    }
    return 0;
}