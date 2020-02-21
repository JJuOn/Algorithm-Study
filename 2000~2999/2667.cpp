#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool bind(int tile[][25], vector<int>& apt, int i, int j, int aptNum, int n, int visited[][25], int& solved) {
	if (i < 0 || i >= n || j < 0 || j >= n) {
		return false;
	}
	if (tile[i][j] == 0 || visited[i][j] == 1) {
		visited[i][j] = 1;
		return false;
	}
	else {
		visited[i][j] = 1;
		solved++;
		if (apt.size() == aptNum) {
			apt.push_back(0);
		}
		apt[aptNum]++;
		bind(tile, apt, i - 1, j, aptNum, n, visited, solved);
		bind(tile, apt, i + 1, j, aptNum, n, visited, solved);
		bind(tile, apt, i, j - 1, aptNum, n, visited, solved);
		bind(tile, apt, i, j + 1, aptNum, n, visited, solved);
		return true;
	}
}

void find(int& i, int& j, int visited[][25], int n, int tile[][25]) {
	for (int i2 = 0; i2 < n; i2++) {
		for (int j2 = 0; j2 < n; j2++) {
			if (!visited[i2][j2] && tile[i2][j2]) {
				i = i2;
				j = j2;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, tile[25][25], visited[25][25], total = 0, solved = 0;
	vector<int> apt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char line[26];
		cin >> line;
		for (int j = n - 1; j >= 0; j--) {
			tile[i][j] = line[j] - '0';
			if (tile[i][j] == 1) {
				total++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
	int i = 0, j = 0, aptNum = 0;
	while (total != solved) {
		if (total != solved) {
			find(i, j, visited, n, tile);
		}
		if (bind(tile, apt, i, j, aptNum, n, visited, solved)) {
			aptNum++;
		}
	}
	sort(apt.begin(), apt.end());
	int size = apt.size();
	cout << size << "\n";
	for (int i = 0; i < size; i++) {
		cout << apt[i] << "\n";
	}
	return 0;
}
