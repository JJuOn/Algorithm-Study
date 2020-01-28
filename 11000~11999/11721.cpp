#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string line;
	cin >> line;
	for (int i = 0; i < line.length(); i++) {
		if (i != 0 && i % 10 == 0) {
			cout << "\n";
		}
		cout << line[i];
	}
	cout << "\n";
	return 0;
}