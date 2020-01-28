#include <iostream>
#include <string>

using namespace std;

int main() {
	string *s;
	int *n,t;
	cin >> t;
	s = new string[t];
	n = new int[t];
	for (int i = 0; i < t; i++) {
		cin >> n[i] >> s[i];
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < s[i].length(); j++) {
			for (int k = 0; k < n[i]; k++) {
				cout << s[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;
	delete[] s;
	delete[] n;
	return 0;
}