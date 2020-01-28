#include <iostream>
using namespace std;
int main() {
	int a[10001];
	for (int i = 1; i <= 10000; i++) {
		a[i] = 1;
	}
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 10000; i++) {
		int num = i;
		do {
			if (num < 10) {
				num = num + num;
			}
			else if (num >= 10 && num < 100) {
				num = num + num / 10 + num % 10;
			}
			else if (num >= 100 && num < 1000) {
				num = num + num / 100 + (num % 100) / 10 + num % 10;
			}
			else if (num >= 1000 && num < 10000) {
				num = num + num / 1000 + (num % 1000) / 100 + (num % 100) / 10 + num % 10;
			}
			else {
				num = 10001;
			}
			if (num <= 10000) {
				a[num] = 0;
			}
		} while (num <= 10000);
	}
	for (int i = 1; i <= 10000; i++) {
		if (a[i] == 1) {
			cout << i << '\n';
		}
	}
	return 0;
}
