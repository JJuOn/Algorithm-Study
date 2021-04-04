#include <iostream>
#include <utility>
#include <vector>

#define INF 2100000000

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, w;
		cin >> n >> m >> w;
		//edge[start][index]={end,weight}
		vector<vector<pair<int, int>>> edges;
		//dist[start][end]=minimum distance
		vector<int> dist;
		edges.resize(n + 1);
		dist.resize(n + 1, INF);
		for (int i = 0; i < m; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edges[s].push_back(make_pair(e, t));
			edges[e].push_back(make_pair(s, t));
		}
		for (int i = 0; i < w; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edges[s].push_back(make_pair(e, -t));
		}
		bool isNegativeCycle = false;
		dist[1] = 0;
		// repeat for the number of vertexes
		for (int k = 0; k < n; k++) {
			// for all vertexes
			for (int i = 1; i <= n; i++) {
				// for all edges of vertex i
				for (int j = 0; j < edges[i].size(); j++) {
					int dest = edges[i][j].first;
					int weight = edges[i][j].second;	
					if (dist[dest] > dist[i] + weight) {
						dist[dest] = dist[i] + weight;
						if (k == n - 1) {
							isNegativeCycle = true;
						}
					}
				}
			}
		}
		if (isNegativeCycle) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}