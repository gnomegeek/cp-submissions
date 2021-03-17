#include <iostream>
using namespace std;

int main() {
    int t;
    int cnt = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
                ans++;
            }
        }

        cout << "Case #" << (cnt++) << ": " << ans << endl;
    }
}