#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b;
	cin >> n;
	while (n--) {
		int sum = 0;
		string s;
		getline(cin, s, ',');
		sum += atoi(s.c_str());
		getline(cin, s);
		sum += atoi(s.c_str());
		cout << sum << "\n";
	}
	return 0;
}