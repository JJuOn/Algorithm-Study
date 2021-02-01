#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int black[6] = { 1,1,2,2,2,8 }, white[6];
	for (int i = 0; i < 6; i++) {
		cin >> white[i];
	}
	for (int i = 0; i < 6; i++) {
		cout << black[i] - white[i] << " ";
	}
	cout << "\n";
	return 0;
}