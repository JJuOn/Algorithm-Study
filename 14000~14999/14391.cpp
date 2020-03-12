#include <iostream>
#include <string>
#include <utility>

#define HORIZONTAL 0
#define VERTICAL 1

using namespace std;

int maxSum = -1;
int a[4][4];
bool visited[4][4];

pair<int, int> findUnvisited(int n, int m) {
	bool found = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				found = true;
				return make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

int findMaxLength(int i, int j, int n, int m, int direction) {
	int length = 0;
	if (direction == HORIZONTAL) {
		for (int k = j; k < m; k++) {
			if (!visited[i][k]) {
				length++;
			}
			else {
				break;
			}
		}
	}
	else {
		for (int k = i; k < n; k++) {
			if (!visited[k][j]) {
				length++;
			}
			else {
				break;
			}
		}
	}
	return length;
}

void makeLineVisited(int i, int j, int direction, int length) {
	if (direction == HORIZONTAL) {
		for (int k = j; k < j + length; k++) {
			visited[i][k] = true;
		}
	}
	else {
		for (int k = i; k < i + length; k++) {
			visited[k][j] = true;
		}
	}
}

void makeLineUnvisited(int i, int j, int direction, int length) {
	if (direction == HORIZONTAL) {
		for (int k = j; k < j + length; k++) {
			visited[i][k] = false;
		}
	}
	else {
		for (int k = i; k < i + length; k++) {
			visited[k][j] = false;
		}
	}
}

int calculateLine(int i, int j, int length, int direction) {
	int sum = 0;
	if (direction == HORIZONTAL) {
		for (int k = j; k < j + length; k++) {
			sum += a[i][k];
			sum *= 10;
		}
	}
	else {
		for (int k = i; k < i + length; k++) {
			sum += a[k][j];
			sum *= 10;
		}
	}
	return sum / 10;
}


void DFS(int n, int m, int sum) {
	pair<int, int> p = findUnvisited(n, m);
	if (p == make_pair(-1, -1)) {
		if (sum > maxSum) {
			maxSum = sum;
		}
		return;
	}
	else {
		int hMaxLength = findMaxLength(p.first, p.second, n, m, HORIZONTAL);
		
		for (int length = 1; length <= hMaxLength; length++) {
			makeLineVisited(p.first, p.second, HORIZONTAL, length);
			int temp = calculateLine(p.first, p.second, length, HORIZONTAL);
			DFS(n, m, sum + temp);
			makeLineUnvisited(p.first, p.second, HORIZONTAL, length);
		}
		int vMaxLength = findMaxLength(p.first, p.second, n, m, VERTICAL);
		for (int length = 1; length <= vMaxLength; length++) {
			makeLineVisited(p.first, p.second, VERTICAL, length);
			int temp = calculateLine(p.first, p.second, length, VERTICAL);
			DFS(n, m, sum + temp);
			makeLineUnvisited(p.first, p.second, VERTICAL, length);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			a[i][j] = line[j] - '0';
			visited[i][j] = false;
		}
	}
	if (n == 0 && m == 0) {
		cout << a[n][m] << "\n";
	}
	else {
		DFS(n, m, 0);
		cout << maxSum << "\n";
	}
	return 0;
}