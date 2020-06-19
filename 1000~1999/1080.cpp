#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

int n, m;
int a[50][50], b[50][50];

void reverseMatrix(int centerI, int centerJ) {
	for (int i = centerI; i <= centerI + 2; i++) {
		for (int j = centerJ; j <= centerJ + 2; j++) {
			a[i][j] = (a[i][j] == 0) ? 1 : 0;
		}
	}
}


int matrixDiff() {
	int diff = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				diff++;
			}
		}
	}
	return diff;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int changes = 0;
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			a[i][j] = line[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			b[i][j] = line[j] - '0';
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				reverseMatrix(i, j);
				changes++;
			}
		}
	}
	if (matrixDiff() == 0) {
		cout << changes << "\n";
	}
	else {
		cout << "-1\n";
	}
	return 0;
}