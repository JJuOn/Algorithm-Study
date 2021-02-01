#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> strs;
	while (true) {
		string s;
		cin >> s;
		if (s == "0") {
			break;
		}
		else {
			strs.push_back(s);
		}
	}
	int size = strs.size();
	for (int i = 0; i < size; i++) {
		bool isPalindrome = true;
		for (int j = 0; j < strs[i].length(); j++) {
			if (strs[i][j] != strs[i][strs[i].length() - 1 - j]) {
				isPalindrome = false;
				break;
			}
		}
		if (isPalindrome) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}