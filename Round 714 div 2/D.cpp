class dsu{
public:
	vector<int>p, siz;
	int n;
	dsu(int _n):n(_n) {
		p.resize(n+1);
		siz.resize(n+1, 1);
		iota(p.begin(), p.end(), 0);
	}

	inline int get(int x) {
		return (x==p[x]?x:(p[x]=get(p[x])));
	}

	inline bool unite(int x, int y) {
		x=get(x);
		y=get(y);

		if (x == y)
			return false;

		if (siz[x] >= siz[y])
			swap(x, y);

		siz[y] += siz[x];
		p[x] = y;
		return true;

	}
};

void solve() {
	int n, p, i;
	cin >> n >> p;
	vi A(n);
	cin >> A;
	
	vector<pair<int, int>> st(n);
	f0(i, n)
		st[i] = {A[i], i};
	sort(all(st));

	dsu D(n);
	ll ans = 0, edges = 0;

	f0(i, n) {
		if (st[i].F >= p)
			break;
		int u = st[i].S;
		int v = D.get(u);

		int next = u + 1;

		while (next < n && D.get(u) != D.get(next) && A[next] % A[u] == 0) {
			D.unite(u, next);
			edges++;
			ans += st[i].F;
			next++;
		}

		next = u - 1;
		while (next >=0 && D.get(u) != D.get(next) && A[next] % A[u] == 0) {
			D.unite(u, next);
			edges++;
			ans += st[i].F;
			next--;
		}
	}
	ans += (n - 1 - edges) * p;
	print(ans);
}
 
