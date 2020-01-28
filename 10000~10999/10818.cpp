#include <iostream>
using namespace std;
int main() {
	int n, *a, min, max;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) {
			min = a[i];
			max = a[i];
		}
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	cout << min << " " << max << endl;
	return 0;
}
