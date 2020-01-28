#include <iostream>

using namespace std;

int main() {
	int n, count = 0;
	int direction = 1;
	cin >> n;
	for (int k = 2; count != n; k++) {
		for (int i = 1; i < k; i++) {
			count++;
			if (count == n) {
				cout << k - i << '/' << i << endl;
				return 0;
			}
		}
		k++;
		for (int i = 1; i < k; i++) {
			count++;
			if (count == n) {
				cout << i << '/' << k - i << endl;
				return 0;
			}
		}
	}
	return 0;
}