#include <iostream>

using namespace std;

int n;

void func(int i, int j, int n) {
	if (n == 3) {
		if (i == 0) {
			if (j == 2) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		else if (i == 1) {
			if (j == 1 || j == 3) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		else {
			if (j >= 0 && j < 5) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
	}
	else {
		if (i < n / 2) {
			func(i, j - n / 2, n / 2);
		}
		else {
			if (j < n) {
				func(i - n / 2, j, n / 2);
			}
			else {
				func(i - n / 2, j - n, n / 2);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2 - 1; j++) {
			func(i, j, n);
		}
		cout << "\n";
	}
	return 0;
}