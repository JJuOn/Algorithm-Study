#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string line;
	for (int count = 0; count < 100; count++) {
		getline(cin, line);
		cout << line << "\n";
	}
	return 0;
}