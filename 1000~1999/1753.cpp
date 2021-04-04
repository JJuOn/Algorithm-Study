#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define INF 2100000000

using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e, start;
	priority_queue<pair<int,int>> pq;
	// first: destination, second: weight
	vector<vector<pair<int,int>>> edge;
	vector<int> dist;

	cin >> v >> e;

	edge.resize(v + 1);
	dist.resize(v + 1, INF);

	cin >> start;
	for (int i = 0; i < e; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		edge[a].push_back(make_pair(b, d));
	}
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int node = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		int size = edge[node].size();
		for (int i = 0; i < size; i++) {
			int dest = edge[node][i].first;
			int weight = edge[node][i].second;
			if (dist[dest] > dist[node] + weight) {
				dist[dest] = dist[node] + weight;
				pq.push(make_pair(-dist[dest], dest));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
}