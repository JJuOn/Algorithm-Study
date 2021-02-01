#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l, p, amount, article[5];
	cin >> l >> p;
	amount = l * p;
	for (int i = 0; i < 5; i++) {
		cin >> article[i];
	}
	for (int i = 0; i < 5; i++) {
		cout << article[i] - amount << " ";
	}
	cout << "\n";
	return 0;
}