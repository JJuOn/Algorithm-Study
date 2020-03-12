#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int tile[500][500];
int tetrominoI[][4] = {
	{0,0,0,0},{0,1,2,3},
	{0,0,1,1},
	{0,1,2,2},{0,0,0,1},{0,-1,0,0},{0,0,1,2},
	{0,1,1,2},{0,-1,-1,0},
	{0,0,0,1},{0,1,1,2},{0,-1,0,0},{0,-1,0,1},
	{0,0,0,1},{0,0,1,2},{0,1,1,1},{0,-2,-1,0},
	{0,0,1,1},{0,-1,0,1} };
int tetrominoJ[][4] = { 
	{0,1,2,3},{0,0,0,0},
	{0,1,0,1},
	{0,0,0,1},{0,1,2,0},{0,2,1,2},{0,1,1,1},
	{0,0,1,1},{0,1,2,1},
	{0,1,2,1},{0,0,1,0},{0,1,1,2},{0,1,1,1},
	{0,1,2,2},{0,1,0,0},{0,0,1,2},{0,1,1,1},
	{0,1,1,2},{0,1,1,0} };

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, m, maxSum = -1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tile[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				int sum = 0;
				for (int l = 0; l < 4; l++) {
					if (i + tetrominoI[k][l] < 0 || i + tetrominoI[k][l] >= n || j + tetrominoJ[k][l] < 0 || j + tetrominoJ[k][l] >= m) {
						break;
					}
					else {
						sum += tile[i + tetrominoI[k][l]][j + tetrominoJ[k][l]];
					}
				}
				if (maxSum < sum) {
					maxSum = sum;
				}
			}
		}
	}
	cout << maxSum << "\n";
	return 0;
}