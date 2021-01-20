#include <iostream>

using namespace std;

bool a[15][15];
int n, result;

bool isValid(int i, int j) {
	for (int k = 0; k < i; k++) {
		if (a[k][j]) {
			return false;
		}
	}
	for (int k = i - 1; k >= 0; k--) {
		if (j - i + k >= 0) {
			if (a[k][j - i + k]) {
				return false;
			}
		}
		else {
			break;
		}
	}
	for (int k = i - 1; k >= 0; k--) {
		if (j + i - k < n) {
			if (a[k][j + i - k]) {
				return false;
			}
		}
		else {
			break;
		}
	}
	return true;
}

void NQueens(int i) {
	if (i == n) {
		result++;
		return;
	}
	else {
		for (int k = 0; k < n; k++) {
			if (!a[i][k] && isValid(i, k)) {
				a[i][k] = true;
				NQueens(i + 1);
				a[i][k] = false;
			}
		}
	}
}

int main() {
	cin >> n;
	NQueens(0);
	cout << result << "\n";
	return 0;
}