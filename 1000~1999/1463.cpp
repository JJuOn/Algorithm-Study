#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, count = 0, *a;
	a = new int[1000001];
	cin >> n;
	a[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			a[i] = min(min(a[i / 2], a[i / 3]), a[i - 1]) + 1;
		}
		else if (i % 2 == 0) {
			a[i] = min(a[i / 2], a[i - 1]) + 1;
		}
		else if (i % 3 == 0) {
			a[i] = min(a[i / 3], a[i - 1]) + 1;
		}
		else {
			a[i] = a[i - 1] + 1;
		}
	}
	cout << a[n] << "\n";
	delete[] a;
	return 0;
}
