#include <iostream>

using namespace std;

int calcDigits(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return n % 10 + calcDigits(n / 10);
	}
}

int main() {
	int n;
	bool found = false;
	cin >> n;
	for (int i = 1; i < n; i++) {
		if (i + calcDigits(i) == n) {
			found = true;
			cout << i << endl;
			break;
		}
	}
	if (!found) {
		cout << 0 << endl;
	}
	return 0;
}