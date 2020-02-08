#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main() {
	string line;
	stack<char> s;
	getline(cin, line);
	int n = atoi(line.c_str());
	while (n--) {
		getline(cin, line);
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != ' ' && i != line.length() - 1) {
				s.push(line[i]);
			}
			else if (line[i]==' '){
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << " ";
			}
			else if (i == line.length() - 1) {
				s.push(line[i]);
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << "\n";
			}
		}
	}
	return 0;
}