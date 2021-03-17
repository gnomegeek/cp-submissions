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


int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, flag = 0;
        cin >> a >> b;
        if(a == b) {
            cout << 0 << endl;    
        } else {
            if(a > b) {
                swap(a, b);
            }
            ll aCopy = a, c = 0, total = 0;
            for(int i = 1; aCopy <= b; i++) {
                aCopy = aCopy*2;
                c++;
                if(aCopy == b) {
                    flag = 1;
                    total = c/3;
                    c = c%3;
                    total = total + c/2;
                    c = c%2;
                    total = total + c;
                }
            }
            if(flag == 1) {
                cout << total << endl;
            } else {
                cout << -1 << endl;
            }
            

        }
    } 
    return 0;
}
