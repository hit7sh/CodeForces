ll ceil_div(ll a, ll b) {
	return (a + b - 1) / b;
}


void solve() {
	int N, M;
    cin >> N >> M;
    vi possible(M + 1, INF), ans(M + 1, INF);
    possible[0] = ans[0] = 0;	
 
    for (int i = 0; i < N; i++) {
        int t, x, y, to;
        cin >> t >> x >> y;
 
        for (int j = 0; j <= M; j++) {
        	if (t == 1) to = j + ceil_div(x, 1e5);
        	else to = ceil_div(j * x, 1e5);

            if (possible[j] + 1 <= y && to <= M) // number of moves <= y and destination <= M
                possible[to] = min(possible[to], possible[j] + 1);
    	}

        for (int j = 1; j <= M; j++)
            if (possible[j] < INF) {
                ans[j] = min(ans[j], i + 1);
                possible[j] = 0;
            }
    }
 
    for (int j = 1; j <= M; j++)
        cout << (ans[j] < INF ? ans[j] : -1) << ' ';
}
