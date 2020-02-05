#include <iostream>

using namespace std;

int a[31];

int main() {
	int n;
	cin >> n;
	a[0] = 1;
	a[1] = 0;
	a[2] = 3;
	for (int i = 3; i <= n; i++) {
		a[i] = a[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			a[i] += (a[j] * 2);
		}
	}
	cout << a[n] << "\n";
	return 0;
}

