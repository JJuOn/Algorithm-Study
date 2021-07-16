#include <iostream>

using namespace std;

enum colors { WHITE, BLUE, MIXED };

int a[128][128];
int blue = 0, white = 0;

void calculate(int start_i, int start_j, int size, int color) {
	if (color == WHITE){
		white++;
		return;
	}
	else if (color == BLUE) {
		blue++;
		return;
	}
	else {
		int delta_i[4] = { 0,0,size / 2,size / 2 };
		int delta_j[4] = { 0,size / 2,0,size / 2 };
		for (int k = 0; k < 4; k++) {
			int beforeColor = a[start_i + delta_i[k]][start_j + delta_j[k]], colorType = beforeColor;
			for (int i = start_i + delta_i[k]; i < start_i + delta_i[k] + size / 2; i++) {
				for (int j = start_j + delta_j[k]; j < start_j + delta_j[k] + size / 2; j++) {
					if (beforeColor != a[i][j]) {
						colorType = MIXED;
					}
				}
			}
			calculate(start_i + delta_i[k], start_j + delta_j[k], size / 2, colorType);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cin >> a[0][0];
	int beforeColor = a[0][0], colorType = beforeColor;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			cin >> a[i][j];
			if (a[i][j] != beforeColor) {
				colorType = MIXED;
			}
		}
	}
	calculate(0, 0, n, colorType);
	cout << white << "\n" << blue << "\n";
	return 0;
}