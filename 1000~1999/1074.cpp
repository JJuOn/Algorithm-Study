#include <iostream>

using namespace std;
int n, r, c, Count = -1;

bool flag = false;

void func(int i, int j, int size) {
	if (!flag) {
		if (size == 0) {
			return;
		}
		if (size == 1) {
			Count++;
			if (i == r && j == c) {
				cout << Count << "\n";
				flag = true;
				return;
			}
		}
		else {
			if (r < i + size / 2 && c < j + size / 2) {
				func(i, j, size / 2);
			}
			else {
				Count += (size / 2)*(size / 2);
			}
			if (r < i + size / 2 && c >= j + size / 2) {
				func(i, j + size / 2, size / 2);
			}
			else {
				Count += (size / 2)*(size / 2);
			}
			if (r >= i + size / 2 && c < j + size / 2) {
				func(i + size / 2, j, size / 2);
			}
			else {
				Count += (size / 2)*(size / 2);
			}
			if (r >= i + size / 2 && c >= j + size / 2) {
				func(i + size / 2, j + size / 2, size / 2);
			}
			else {
				Count += (size / 2)*(size / 2);
			}
		}
	}
	else {
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> r >> c;
	n = (1 << n);
	func(0, 0, n);
	return 0;
}