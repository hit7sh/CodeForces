#include<bits/stdc++.h>
using namespace std;

int main() {
	int64_t n, m, u, v, w, i, j;
	cin >> n >> m;

	vector<vector<pair<int64_t, int64_t>>> adj(n+1);

	while (m--) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	vector<vector<vector<int64_t>>> vis(n+1, vector<vector<int64_t>>(2, vector<int64_t>(2)));
	vector<vector<vector<int64_t>>> dist(n+1, vector<vector<int64_t>>(2, vector<int64_t>(2)));

	priority_queue<array<int64_t, 4>, vector<array<int64_t, 4>>, greater<array<int64_t, 4>>> q; 
	// dist, vertex, skipped, twice  -> skipped, twice are the states

	q.push({0, 1, 0, 0});

	while (!q.empty()) {
		auto cur = q.top();
		q.pop();

		if (vis[cur[1]][cur[2]][cur[3]])
			continue;

		vis[cur[1]][cur[2]][cur[3]] = 1;
		dist[cur[1]][cur[2]][cur[3]] = cur[0];

		for (int i : {0, 1}) {
			for (int j : {0, 1}) {

				if (i < cur[2] or j < cur[3])
					continue;

				for (auto& [v, w] : adj[cur[1]]) {
					q.push({cur[0] + w*(1+(j > cur[3]) - (i > cur[2])), v, i, j});
				}
			}
		}
	}

	for (i = 2; i <= n; i++)
		cout << (dist[i][1][1]) << ' ';
}
