#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 3e5 + 5;

int add(int a, int b) { return (a + b) % MOD; }
int mul(int a, int b) { return 1ll * a * b % MOD; }

struct line {
    int a,b;
    line() : a(0), b(0) {}
    line(int x, int y) : a(x), b(y) {}
    line operator + (line &other) {
        return line(add(a, other.a), add(b, other.b));
    }
};

int n,q;
int timer;
int h[N];
int tin[N];
int tout[N];
line T[4 * N];
vector<int> G[N];

void update(int pos, line x, int id = 1, int tl = 0, int tr = n) {
    if (tl == tr) T[id] = T[id] + x;
    else {
        int tm = (tl + tr) / 2;
        if (pos > tm) update(pos, x, 2 * id + 1, tm + 1, tr);
        else update(pos, x, 2 * id, tl, tm);
        T[id] = T[2 * id] + T[2 * id + 1];
    }
}

line query(int l, int r, int id = 1, int tl = 0, int tr = n) {
    if (l > r) return line();
    if (l == tl and r == tr) return T[id];
    int tm = (tl + tr) / 2;
    line valL = query(l, min(r, tm), 2 * id, tl, tm);
    line valR = query(max(l, tm + 1), r, 2 * id + 1, tm + 1, tr);
    return valL + valR;
}

void dfs(int u) {
    tin[u] = timer++;
    for (int v : G[u]) {
        dfs(v);
        h[v] = h[u] + 1;
    }
    tout[u] = timer - 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u; cin >> u;
        G[--u].emplace_back(i);
    }
    dfs(0);
    cin >> q;
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int v,x,k;
            cin >> v >> x >> k;
            v--;
            int a = add(0, MOD - k);
            int b = add(x, mul(k, h[v]));
            update(tin[v], line(a, b));
            update(tout[v] + 1, line(add(0, MOD - a), add(0, MOD - b)));
        } else {
            int v; cin >> v;
            v--;
            line q = query(0, tin[v]);
            cout << add(mul(q.a, h[v]), q.b) << '\n';
        }

    }
    return 0;
}
