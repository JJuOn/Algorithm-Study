#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	string line;
	deque<char> d;
	int sum = 0, depth = 0;
	cin >> line;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == '(') {
			depth++;
		}
		else if (line[i] == ')') {
			if (d.back() == '(') {
				d.pop_back();
				depth--;
				sum += depth;
			}
			else if (d.back() == ')') {
				d.pop_back();
				sum += 1;
				depth--;
			}
		}
		d.push_back(line[i]);
	}
	cout << sum << "\n";
	return 0;
}