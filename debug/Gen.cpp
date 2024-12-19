#include <bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

using ll = long long;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll random(ll L, ll R) {
    return uniform_int_distribution<ll>(L, R)(rnd);
}

int main() {
    int n = 10;
    int q = 10;
    cout << n << " " << q << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = random(0, 4);
            cout << (char)mp[x];
        }
        cout << '\n';
    }
    return 0;
}
