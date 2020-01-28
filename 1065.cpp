#include <iostream>
using namespace std;
int calDigit(int num) {
	int digit = 0;
	while (num) {
		num = num / 10;
		digit++;
	}
	return digit;
}
int main() {
	int n, digit, count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		digit = calDigit(i);
		if (digit == 1 || digit == 2) {
			count++;
		}
		else {
			int d[3];
			d[0] = i / 100;
			d[1] = i % 100 / 10;
			d[2] = i % 10;
			if (d[0] - d[1] == d[1] - d[2]) {
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
