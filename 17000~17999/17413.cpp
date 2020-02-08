#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	string line;
	deque<char> d;
	getline(cin, line);
	bool isTag;
	if (line[0] == '<') {
		isTag = true;
	}
	else {
		isTag = false;
	}
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
			while (!d.empty()) {
				cout << d.front();
				d.pop_front();
			}
			cout << " ";
		}
		else if (line[i] == '<') {
			isTag = true;
			d.push_back(line[i]);
		}
		else if (line[i] == '>') {
			isTag = false;
			while (!d.empty()) {
				cout << d.front();
				d.pop_front();
			}
			cout << ">";
		}
		else {
			if (isTag) {
				d.push_back(line[i]);
			}
			else {
				d.push_front(line[i]);
			}
		}
	}
	while (!d.empty()) {
		cout << d.front();
		d.pop_front();
	}
	return 0;
}