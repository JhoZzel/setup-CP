#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end());
    ll num = 0;
    ll den = n;
    for (int i = 0, k = 3 - 2 * n; i < n; i++, k += 4) {
        num += 1ll * a[i] * k;
    }
    ll g = gcd(num,den);
    num /= g; den /= g;
    cout << num << " " << den << '\n';
    return 0;
}
