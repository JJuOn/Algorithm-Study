#include <iostream>
using namespace std;
int main() {
	int r[42] = { 0 }, n[10], count = 0;
	for (int i = 0; i < 10; i++) {
		cin >> n[i];
		r[n[i] % 42] = 1;
	}
	for (int i = 0; i < 42; i++) {
		count += r[i];
	}
	cout << count << endl;
	return 0;
}
