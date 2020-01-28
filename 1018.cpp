#include <iostream>
#include <string>

using namespace std;

//white: true, black: false
int main() {
	int n, m;
	cin >> n >> m;
	bool** board = new bool*[n];
	for (int i = 0; i < n; i++) {
		board[i] = new bool[m];
	}
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'W') {
				board[i][j] = true;
			}
			else {
				board[i][j] = false;
			}
		}
	}
	int minMiss=m*n+1, miss;
	bool flag;
	for (int k = 0; k < n - 7; k++) {
		for (int l = 0; l < m - 7; l++) {
			flag = true;
			miss = 0;
			for (int i = k; i < k + 8; i++) {
				for (int j = l; j < l + 8; j++) {
					if (board[i][j] != flag) {
						miss++;
					}
					flag = !flag;
				}
				flag = !flag;
			}
			if (miss < minMiss) {
				minMiss = miss;
			}
			flag = false;
			miss = 0;
			for (int i = k; i < k + 8; i++) {
				for (int j = l; j < l + 8; j++) {
					if (board[i][j] != flag) {
						miss++;
					}
					flag = !flag;
				}
				flag = !flag;
			}
			if (miss < minMiss) {
				minMiss = miss;
			}
		}
	}
	cout << minMiss << endl;
	for (int i = 0; i < n; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}