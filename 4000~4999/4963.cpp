#include <iostream>
#include <vector>

using namespace std;

void find(int& i, int& j, int w, int h, int a[][50], int visited[][50]) {
	for (int i2 = 0; i2 < h; i2++) {
		for (int j2 = 0; j2 < w; j2++) {
			if (!visited[i2][j2] && a[i2][j2]) {
				i = i2;
				j = j2;
				return;
			}
		}
	}
}

bool bind(int i, int j, int w, int h, int a[][50], int visited[][50], int& count) {
	if (i < 0 || j < 0 || i >= h || j >= w) {
		return false;
	}
	else if (visited[i][j] || !a[i][j]) {
		return false;
	}
	else {
		visited[i][j] = 1;
		count++;
		bind(i - 1, j - 1, w, h, a, visited, count);
		bind(i - 1, j, w, h, a, visited, count);
		bind(i - 1, j + 1, w, h, a, visited, count);
		bind(i, j - 1, w, h, a, visited, count);
		bind(i, j + 1, w, h, a, visited, count);
		bind(i + 1, j - 1, w, h, a, visited, count);
		bind(i + 1, j, w, h, a, visited, count);
		bind(i + 1, j + 1, w, h, a, visited, count);
		return true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int w, h;
	cin >> w >> h;
	while (w && h) {
		int a[50][50], count = 0, visited[50][50], total = 0;
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
				if (a[i][j]) {
					total++;
				}
			}
		}
		int islandNum = 0;
		int i = 0, j = 0;
		while (count != total) {
			find(i, j, w, h, a, visited);
			if (bind(i, j, w, h, a, visited, count)) {
				islandNum++;
			}
		}
		cout << islandNum << "\n";
		cin >> w >> h;
	}
	return 0;
}