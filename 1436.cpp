#include <iostream>

using namespace std;

bool isEnd(int n) {
	int count = 0;
	while (n) {
		int digit = n % 10;
		if (digit == 6) {
			count++;
			if (count == 3) {
				return true;
			}
		}
		else {
			count = 0;
		}
		n /= 10;
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int i = 666;
	while (n) {
		if (isEnd(i)) {
			n--;
		}
		i++;
	}
	cout << i - 1 << endl;
	return 0;
}