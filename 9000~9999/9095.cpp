#include <iostream>

using namespace std;

int a[12];

int main() {
	int n, num;
	cin >> n;
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	while (n--) {
		cin >> num;
		for (int i = 4; i <= num; i++) {
			a[i] = a[i - 1] + a[i - 2] + a[i - 3];
		}
		cout << a[num] << "\n";
	}
	
	return 0;
}
