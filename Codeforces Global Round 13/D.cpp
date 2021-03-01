 
void solve() {	
	int u, v, i;
	vi bx, by;
	cin >> u >> v;
	for (int bit = 0; bit < 30; bit++) {
		if (u & (1 << bit))
			bx.EB(bit);
		if (v & (1 << bit))
			by.EB(bit);
	}
	bool ok = u <= v;
	if (sz(bx) < sz(by))
		ok = 0;
	else
		f0(i, sz(by))
			if (bx[i] > by[i])
				ok = 0;
	Yes(ok);
}
 
 
