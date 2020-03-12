#include <iostream>

using namespace std;

char board[51][51];
int maxCount = -1;

void swap(int i1, int j1, int i2, int j2) {
	char temp;
	temp = board[i1][j1];
	board[i1][j1] = board[i2][j2];
	board[i2][j2] = temp;
	return;
}

int check(int n) {
	int count;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int k = i;
			count = 0;
			while (k >= 0 && k < n && board[k][j] == board[i][j]) {
				count++;
				k++;
			}
			if (count > maxCount) {
				maxCount = count;
			}
			k = j;
			count = 0;
			while (k >= 0 && k < n && board[i][k] == board[i][j]) {
				count++;
				k++;
			}
			if (count > maxCount) {
				maxCount = count;
			}
		}
	}
	return maxCount;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	char line[51];
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) {
			board[i][j] = line[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + 1 < n && board[i][j] != board[i + 1][j]) {
				swap(i, j, i + 1, j);
				check(n);
				swap(i, j, i + 1, j);
			}
			if (j + 1 < n && board[i][j] != board[i][j + 1]) {
				swap(i, j, i, j + 1);
				check(n);
				swap(i, j, i, j + 1);
			}
		}
	}
	cout << maxCount << "\n";
	return 0;
}