#include <iostream>
#include <string>
#define BASE 97

using namespace std;

int main() {
	int alphabets[26];
	fill_n(alphabets, 26, -1);
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (alphabets[(int)str[i] - BASE] == -1) {
			alphabets[(int)str[i] - BASE] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabets[i] << " ";
	}
	return 0;
}