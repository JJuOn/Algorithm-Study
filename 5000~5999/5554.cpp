#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int time[4], sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> time[i];
		sum += time[i];
	}
	cout << sum / 60 << "\n" << sum % 60 << "\n";
	return 0;
}