// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n"

#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )

#define f1(i, n)  for (i = 1; i <=(int)(n); i++)


using namespace std;
const int mod = 1e9+7, mxN = 2e5+5, INF = 0x3f3f3f3f;


template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }


struct segment { // segment tree
	int mx = -INF, mn = INF;
} st[4*mxN];

int n, A[mxN];

ostream& operator<<(ostream& ot, segment s) { ot << s.mn << ' ' << s.mx; return ot; }

segment cmb(segment a, segment b) {
	segment res = {max(a.mx, b.mx), min(a.mn, b.mn)};
	return res;
}

void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		st[v].mx = st[v].mn = A[tl];
	else {
		int tm = (tl + tr)/2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);
		st[v] = cmb(st[2*v], st[2*v+1]);
	}
}

segment qry(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r or l < 1 or r > n) {
		segment s;
		return s;
	} else if (l == tl && r == tr)  {
		return st[v];
	} else {
		int tm = (tl + tr)/2;
		return cmb(qry(l, min(r, tm), 2*v, tl, tm), qry(max(l, tm+1), r, 2*v+1, tm+1, tr));
	}
}

void solve() {
	int i, q, l, r;
	cin >> n >> q;
  
	f1(i, n) {
		char x; 
    cin >> x;
    
		if (x == '+')
			A[i] = A[i-1] + 1;
		else
			A[i] = A[i-1] - 1;
	}
  
	build();
	
	while(q--) {
		cin >> l >> r;
		int _min = 0, _max = 0;
    
		if (l - 1 >= 1)_min = min(_min, qry(1, l - 1).mn); // left exists
		if (n >= r + 1)_min = min(_min, qry(r + 1, n).mn - (A[r] - A[l - 1])); // right exists
 
		if (l - 1 >= 1)_max = max(_max, qry(1, l - 1).mx);
		if (n >= r + 1)_max = max(_max, qry(r + 1, n).mx - (A[r] - A[l - 1]));
 
		print(_max - _min + 1);
	}

	segment s;
	f1(i, 4*n)
		st[i] = s;
    
}



int main() {

    __speed() tt solve();

    return 0;
}
