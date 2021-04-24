#include <iostream>

using namespace std;

int days[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, total = 0;
	cin >> x >> y;
	for (int i = 1; i < x; i++) {
		total += days[i];
	}
	int diff = total + y - 1;
	if (diff % 7 == 0) {
		cout << "MON\n";
	}
	else if (diff % 7 == 1) {
		cout << "TUE\n";
	}
	else if (diff % 7 == 2) {
		cout << "WED\n";
	}
	else if (diff % 7 == 3) {
		cout << "THU\n";
	}
	else if (diff % 7 == 4) {
		cout << "FRI\n";
	}
	else if (diff % 7 == 5) {
		cout << "SAT\n";
	}
	else {
		cout << "SUN\n";
	}
	return 0;
}