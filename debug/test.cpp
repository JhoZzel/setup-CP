#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << 1 << '\n';
    int n = 6593;
    int m = 152;
    srand(time(NULL));
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int r = rand() % 2;
            if (r & 1) cout << "#";
            else cout << ".";
        }
        cout << '\n';
    }
    return 0;
}
