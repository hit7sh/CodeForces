void init() {
	int i, j;
	// cnt[0] = 1;
	f0(i, 10) {
		int n = i;
		vl cnt(10);
		do cnt[n % 10]++; while (n && (n /= 10));
		f0(j, mxN) {
			if (j == 0)
				steps[i][j] = to_string(n).length();
			else {
				for (int k = 0; k < 10; k++)
					steps[i][j] += cnt[k];
			}
			vl nc(10);
			for (int k = 0; k < 9; k++)
				nc[k + 1] = cnt[k];
			nc[0] = cnt[9];
			nc[1] = add(nc[1], cnt[9]);
			cnt = nc;
		}
	}
}
