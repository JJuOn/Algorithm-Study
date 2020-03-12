#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	bool s[21];
	cin >> n;
	for (int i = 0; i < 21; i++) {
		s[i] = false;
	}
	while (n--) {
		string opr1;
		int opr2;
		cin >> opr1;
		if (opr1 == "add") {
			cin >> opr2;
			if (!s[opr2]) {
				s[opr2] = true;
			}
		}
		else if (opr1 == "remove") {
			cin >> opr2;
			if (s[opr2]) {
				s[opr2] = false;
			}
		}
		else if (opr1 == "check") {
			cin >> opr2;
			if (s[opr2]) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (opr1 == "toggle") {
			cin >> opr2;
			s[opr2] = !s[opr2];
		}
		else if (opr1 == "all") {
			for (int i = 1; i <= 20; i++) {
				s[i] = true;
			}
		}
		else if (opr1 == "empty") {
			for (int i = 1; i <= 20; i++) {
				s[i] = false;
			}
		}
	}
	return 0;
}