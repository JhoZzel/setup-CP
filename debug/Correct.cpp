#include <bits/stdc++.h>
using namespace std;

const int N = 300000 + 5;
const int MOD = 1e9 + 7;

struct line {
	int m;
	int b;
	line(){
		m = b = 0;
	}
	
	line(int m, int b) : m(m), b(b) {
		
	}
	
	line operator + (const line &rhs) const {
		return line((m + rhs.m) % MOD, (b + rhs.b) % MOD);
	}
	
	int operator () (const int x) const {
		return (1ll * m * x + b) % MOD;
	}
};

int n;
int q;
int T;
int h[N];
int in[N];
int out[N];
line st[4 * N];
vector<int> G[N];

void DFS(int u) {
	in[u] = T++;
	for(int v : G[u]) {
		h[v] = h[u] + 1;
		DFS(v);
	}
	out[u] = T - 1;
}

void update(int x, line y, int pos = 1, int l = 0, int r = n) {
	if(l == r) {
		st[pos] = st[pos] + y;
		return;
	}
	int mi = (l + r) / 2;
	if(x <= mi) update(x, y, 2 * pos, l, mi);
	else update(x, y, 2 * pos + 1, mi + 1, r);
	st[pos] = st[2 * pos] + st[2 * pos + 1];
}

line query(int x, int y, int pos = 1, int l = 0, int r = n) {
	if(y < l or r < x or x > y) return line();
	if(x <= l and r <= y) return st[pos];
	int mi = (l + r) / 2;
	return query(x, y, 2 * pos, l, mi) + query(x, y, 2 * pos + 1, mi + 1, r);
}

int main() {
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	for(int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		G[p].emplace_back(i);
	}
	DFS(1);
	cin >> q;
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			int v, x, k;
			cin >> v >> x >> k;
			int m = (MOD - k) % MOD;
			int b = (x + (1ll * k * h[v]) % MOD) % MOD;
			update(in[v], line(m, b));
			update(out[v] + 1, line((MOD - m) % MOD, (MOD - b) % MOD));
		}
		else {
			int v;
			cin >> v;
			cout << query(0, in[v])(h[v]) << endl;
		}
	}
	return 0;
}
