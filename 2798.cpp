#include <iostream>

using namespace std;

int main() {
	int n, m, *card;
	cin >> n >> m;
	card = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	int max=0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (card[i] + card[j] + card[k] > m) {
					continue;
				}
				else if (card[i] + card[j] + card[k] > max) {
					max = card[i] + card[j] + card[k];
				}
			}
		}
	}
	cout << max << endl;
	delete[] card;
	return 0;
}