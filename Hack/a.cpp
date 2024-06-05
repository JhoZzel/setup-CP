#include <bits/stdc++.h>
#define dbg(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int f[] = {0, 1, 2, 3, 4, 5, 5, 7, 6, 6};

int main() {
    string s; cin >> s;
    const int n = s.size();
    s += "$";
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (s[j + 1] == '0') j++;
        if (j != i) {
            int r = stoi(s.substr(i, j - i + 1));
            for (int d = 2; d <= r; d++) {
                while(r % d == 0) {
                    ans += d;
                    r /= d;
                }
            }
            if (r != 1) {
                ans += f[r];
            }
            i = j;
        }
        else {
            ans += f[s[i] - '0'];
        }
    }
    cout << ans << '\n';
    return 0;
}
