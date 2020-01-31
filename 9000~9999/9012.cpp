#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string line;
	
	int n;
	cin >> n;
	while (n--) {
		cin >> line;
		bool vps = true;
		stack<char> s;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '(') {
				s.push('(');
			}
			else if (line[i] == ')') {
				if (!s.empty()) {
					s.pop();
				}
				else {
					vps = false;
				}
			}
		}
		if (vps && s.empty()) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}
