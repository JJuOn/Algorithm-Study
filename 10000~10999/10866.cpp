#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	string opr1;
	int n, opr2;
	deque<int> d;
	cin >> n;
	while (n--) {
		cin >> opr1;
		if (opr1 == "push_front") {
			cin >> opr2;
			d.push_front(opr2);
		}
		else if (opr1 == "push_back") {
			cin >> opr2;
			d.push_back(opr2);
		}
		else if (opr1 == "pop_front") {
			if (d.empty()) {
				cout << "-1\n";
			}
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		}
		else if (opr1 == "pop_back") {
			if (d.empty()) {
				cout << "-1\n";
			}
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}
		}
		else if (opr1 == "size") {
			cout << d.size() << "\n";
		}
		else if (opr1 == "empty") {
			if (d.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (opr1 == "front") {
			if (d.empty()) {
				cout << "-1\n";
			}
			else {
				cout << d.front() << "\n";
			}
		}
		else if (opr1 == "back") {
			if (d.empty()) {
				cout << "-1\n";
			}
			else {
				cout << d.back() << "\n";
			}
		}
	}
	return 0;
}