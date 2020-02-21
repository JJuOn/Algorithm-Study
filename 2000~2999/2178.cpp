#include <iostream>
#include <queue>

using namespace std;

struct CoordType {
	int i;
	int j;
	int count;
	CoordType(int i, int j, int count) :i(i), j(j), count(count) {}
};

int a[100][100];
bool visited[100][100];

int BFS(int h, int w) {
	queue<CoordType> q;
	CoordType first(0, 0, 1);
	q.push(first);
	visited[first.i][first.j] = 1;
	CoordType node(0, 0, 1);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node.i == h - 1 && node.j == w - 1) {
			return node.count;
		}
		if (node.i - 1 >= 0 && a[node.i - 1][node.j] && !visited[node.i - 1][node.j]) {
			CoordType temp(node.i - 1, node.j, node.count + 1);
			q.push(temp);
			visited[node.i - 1][node.j] = true;
		}
		if (node.i + 1 < h && a[node.i + 1][node.j] && !visited[node.i + 1][node.j]) {
			CoordType temp(node.i + 1, node.j, node.count + 1);
			q.push(temp);
			visited[node.i + 1][node.j] = true;
		}
		if (node.j - 1 >= 0 && a[node.i][node.j - 1] && !visited[node.i][node.j - 1]) {
			CoordType temp(node.i, node.j - 1, node.count + 1);
			q.push(temp);
			visited[node.i][node.j - 1] = true;

		}
		if (node.j + 1 < w && a[node.i][node.j + 1] && !visited[node.i][node.j + 1]) {
			CoordType temp(node.i, node.j + 1, node.count + 1);
			q.push(temp);
			visited[node.i][node.j + 1] = true;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int w, h;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		char line[101];
		cin >> line;
		for (int j = 0; j < w; j++) {
			a[i][j] = line[j] - '0';
		}
	}
	int count = BFS(h, w);
	cout << count << "\n";
	return 0;
}