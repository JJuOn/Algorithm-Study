#include <iostream>

using namespace std;

void swap(int* a, int* b) {

}

void quickSort(int** pos, int left, int right) {
	if (left >= right) {
		return;
	}
	int i = left - 1;
	int j = left;
	int pivot = right;
	for (; j < right; j++) {
		if (pos[j][0] < pos[pivot][0]) {
			int temp[2];
			i++;
			temp[0] = pos[j][0];
			temp[1] = pos[j][1];
			
			pos[j][0] = pos[i][0];
			pos[j][1] = pos[i][1];

			pos[i][0] = temp[0];
			pos[i][1] = temp[1];
		}
		else if (pos[j][0] == pos[pivot][0] && pos[j][1] < pos[pivot][1]) {
			int temp[2];
			i++;
			temp[0] = pos[j][0];
			temp[1] = pos[j][1];

			pos[j][0] = pos[i][0];
			pos[j][1] = pos[i][1];

			pos[i][0] = temp[0];
			pos[i][1] = temp[1];
		}
	}
	int temp[2];
	i++;
	temp[0] = pos[i][0];
	temp[1] = pos[i][1];

	pos[i][0] = pos[pivot][0];
	pos[i][1] = pos[pivot][1];

	pos[pivot][0] = temp[0];
	pos[pivot][1] = temp[1];

	quickSort(pos, left, i - 1);
	quickSort(pos, i + 1, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, i = 0, **pos;
	cin >> n;
	pos = new int* [n];
	for (int i = 0; i < n; i++) {
		pos[i] = new int[2];
	}
	for (int i = 0; i < n; i++) {
		cin >> pos[i][0] >> pos[i][1];
	}
	quickSort(pos, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << pos[i][0] << " " << pos[i][1] << "\n";
	}
	for (int i = 0; i < n; i++) {
		delete[] pos[i];
	}
	delete[] pos;
	return 0;
}