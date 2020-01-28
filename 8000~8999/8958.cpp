#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, count = 0,score;
	string *str;
	cin >> n;
	str = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < n; i++) {
		score = 0;
		count = 0;
		for (int j = 0; j < str[i].length(); j++) {
			if (str[i][j] == 'O') {
				count++;
				score += count;
			}
			else {
				count = 0;
			}
		}
		cout << score << endl;
	}
	return 0;
}