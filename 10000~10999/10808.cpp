#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int alphabets[26];
	for (int i = 0; i < 26; i++) {
		alphabets[i] = 0;
	}
	for (int i = 0; i < s.length(); i++) {
		alphabets[(int)s[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabets[i] << " ";
	}
	return 0;
}
