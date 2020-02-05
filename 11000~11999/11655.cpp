#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' || ((int)s[i] >= 48 && (int)s[i] <= 57)) {
			cout << s[i];
		}
		else if (islower(s[i])) {
			cout << (char)(((int)s[i] + 13 - 97) % 26 + 97);
		}
		else if (isupper(s[i])) {
			cout << (char)(((int)s[i] + 13 - 65) % 26 + 65);
		}
	}
	return 0;
}
