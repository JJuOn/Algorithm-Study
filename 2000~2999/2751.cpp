#include <iostream>

using namespace std;

void merge(int list[], int left, int mid, int right);
void mergeSort(int list[], int left, int right);

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	mergeSort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
	delete[] a;
	return 0;
}

void merge(int list[], int left, int mid, int right) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = 0;
	int *temp = new int[right - left + 1];
	while (i <= mid && j <= right) {
		if (list[i] < list[j]) {
			temp[k++] = list[i++];
		}
		else {
			temp[k++] = list[j++];
		}
	}
	if (i > mid) {
		for (; j <= right; j++) {
			temp[k++] = list[j];
		}
	}
	else {
		for (; i <= mid; i++) {
			temp[k++] = list[i];
		}
	}
	k = 0;
	for (int l = left; l <= right; l++) {
		list[l] = temp[k++];
	}
	delete[] temp;
}

void mergeSort(int list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}