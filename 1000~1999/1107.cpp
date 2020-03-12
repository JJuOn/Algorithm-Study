#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool broken[10];

bool canType(int n, int& digit) {
	bool flag;
	if (n == 0) {
		digit = 1;
		if (!broken[0]) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		flag = true;
		digit = 0;
		while (n) {
			digit++;
			if (broken[n % 10]) {
				flag = false;
				break;
			}
			n /= 10;
		}
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, m, temp = 100, digit, minCount = 500001;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int brokenNum;
		cin >> brokenNum;
		broken[brokenNum] = true;
	}
	minCount = abs(temp - n);
	for (int i = 0; i <= 1000000; i++) {
		if (canType(i, digit)) {
			int count = digit + abs(i - n);
			if (minCount > count) {
				minCount = count;
			}
		}
	}
	cout << minCount << "\n";
	return 0;
}