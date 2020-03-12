#include <iostream>
#include <string>

using namespace std;

int n, a[10], sum[10][10];
int s[10][10];
bool found = false;

void updateSum(int j) {
	if (j == 0) {
		sum[0][0] = a[0];
	}
	else {
		for (int i = 0; i <= j; i++) {
			sum[i][j] = sum[i][j - 1] + a[j];
		}
	}
}

void DFS(int j) {
	if (j == n) {
		found = true;
		return;
	}
	else {
		for (int k = -10; k <= 10; k++) {
			bool match = true;
			a[j] = k;
			updateSum(j);
			for (int i = 0; i <= j; i++) {
				if (s[i][j] == '-') {
					if (!(sum[i][j] < 0)) {
						match = false;
						break;
					}
				}
				else if (s[i][j] == '0') {
					if (!(sum[i][j] == 0)) {
						match = false;
						break;
					}
				}
				else if (s[i][j] == '+') {
					if (!(sum[i][j] > 0)) {
						match = false;
						break;
					}
				}
			}
			if (match) {
				DFS(j + 1);
			}
			if (found) {
				break;
			}
		}
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	string line;
	cin >> n;
	cin >> line;
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			s[i][j] = line[k];
			k++;
		}
		s[i][n] = '\0';
	}
	DFS(0);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}