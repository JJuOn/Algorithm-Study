#include <iostream>

using namespace std;

int main() {
	int f[45], n;
	cin >> n;
	if (n == 0) {
		cout << 0 << "\n";
	}
	else if (n == 1) {
		cout << 1 << "\n";
	}
	else {
		f[0] = 0;
		f[1] = 1;
		for (int i = 2; i <= n; i++) {
			f[i] = f[i - 1] + f[i - 2];
		}
		cout << f[n] << "\n";
	}

	return 0;
}
