#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	int n;
	stack<char> s,temp;
	char opr1, opr2;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		s.push(str[i]);
	}
	cin >> n;
	while (n--) {
		cin >> opr1;
		if (opr1 == 'L') {
			if (!s.empty()) {
				temp.push(s.top());
				s.pop();
			}
		}
		else if (opr1 == 'D') {
			if (!temp.empty()) {
				s.push(temp.top());
				temp.pop();
			}
		}
		else if(opr1 == 'B') {
			if (!s.empty()) {
				s.pop();
			}
		}
		else if (opr1 == 'P') {
			cin >> opr2;
			s.push(opr2);
		}
	}
	while (!s.empty()) {
		temp.push(s.top());
		s.pop();
	}
	while (!temp.empty()) {
		cout << temp.top();
		temp.pop();
	}
	return 0;
}