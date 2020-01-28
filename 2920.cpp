#include <iostream>
using namespace std;
int main() {
	int before, now, status;
	cin >> before;
	for (int i = 0; i < 7; i++) {
		cin >> now;
		if (before - now != 1 && before - now != -1) {
			status = 2;
			break;
		}
		else if (before - now == -1) {
			status = 0;
		}
		else {
			status = 1;
		}
		before = now;
	}
	if (status == 0) {
		cout << "ascending\n";
	}
	else if (status == 1) {
		cout << "descending\n";
	}
	else {
		cout << "mixed";
	}
	return 0;
}