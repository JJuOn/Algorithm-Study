#include <iostream>
#include <string>

using namespace std;

int main() {
	for (int count = 0; count < 100; count++) {
		string s;
		int lower = 0, upper = 0, number = 0, blank = 0;
		getline(cin, s);
		if (s.length() == 0) {
			break;
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				lower++;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				upper++;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				number++;
			}
			else if (s[i] == ' ') {
				blank++;
			}
		}
		cout << lower << " " << upper << " " << number << " " << blank << "\n";
	}
	return 0;
}
