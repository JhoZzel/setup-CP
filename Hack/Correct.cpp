#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int dp[N];

vector<int> get_div(int x) {
    vector<int> D;
    for (int d = 2; d * d <= x; d++) {
        if (x % d) continue;
        D.emplace_back(d);
        D.emplace_back(x / d);
    }
    return D;
}

int main() {
    dp[1] = 1;
    for (int x = 2; x < N; x++) {
        dp[x] = 1 + dp[x - 1];
        // add 
        for (int d = 2; d < 20; d++) {
            if (x - d <= 0) break; 
            dp[x] = min(dp[x], dp[d] + dp[x - d]);
        }
        // multiplication
        vector<int> D = get_div(x);
        for (int d : D) {
            dp[x] = min(dp[x], dp[d] + dp[x / d]);
        }
        // join
        string s = to_string(x);
        const int len = s.size();
        for (int L = 1; L < len; L++) {
            string r1 = s.substr(0,L);
            string r2 = s.substr(L,len);
            if (r2[0] == '0') continue;
            int x1 = stoi(r1), x2 = stoi(r2);
            dp[x] = min(dp[x], dp[x1] + dp[x2]);
        }
    }
    
    int n; 
    cin >> n;
    cout << dp[n] << '\n';
    return 0;
}

