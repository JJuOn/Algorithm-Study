#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string e = a + b, f = c + d;
	cout << stoll(e.c_str()) + stoll(f.c_str()) << "\n";
	return 0;
}
