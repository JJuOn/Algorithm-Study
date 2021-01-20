#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> num(3);
vector<vector<int>> a;

bool allSame(int posI, int posJ, int size) {
	bool same = true;
	int first = a[posI][posJ];
	for (int i = posI; i < posI + size; i++) {
		for (int j = posJ; j < posJ + size; j++) {
			if (a[i][j] != first) {
				same = false;
				break;
			}
		}
		if (!same) {
			break;
		}
	}
	return same;
}

void check(int posI, int posJ, int size) {
	if (size == 0) {
		return;
	}
	else {
		if (allSame(posI, posJ, size)) {
			num[a[posI][posJ] + 1]++;
		}
		else {
			for (int i = posI; i < posI + size; i += size / 3) {
				for (int j = posJ; j < posJ + size; j += size / 3) {
					check(i, j, size / 3);
				}
			}
		}
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	check(0, 0, n);
	for (int i = 0; i < 3; i++) {
		cout << num[i] << "\n";
	}
	return 0;
}