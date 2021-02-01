#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, i;
	cin >> a >> i;
	cout << a * i - (a - 1) << "\n";
	return 0;
}