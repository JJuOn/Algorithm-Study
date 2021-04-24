#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * n - 1 - 2 * i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * n - 1 - 2 * i; j++) {
			cout << "*";
		}
		if (i != 0) {
			cout << "\n";
		}
	}
	return 0;
}