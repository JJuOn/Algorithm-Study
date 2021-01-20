#include <iostream>
#include <vector>

using namespace std;

int n;
long long swapCount;
vector<int> v, sorted;

void merge(int start, int mid, int end) {
	int i = start, j = mid + 1, k = start, localCount = 0;
	while (i <= mid && j <= end) {
		if (v[i] <= v[j]) {
			sorted[k] = v[i];
			swapCount+=localCount;
			i++;
			k++;
		}
		else if (v[i] > v[j]) {
			sorted[k] = v[j];
			localCount++;
			j++;
			k++;
		}
	}
	if (i <= mid) {
		for (; i <= mid; i++) {
			sorted[k] = v[i];
			swapCount += localCount;
			k++;
		}
	}
	else if (j <= end) {
		for (; j <= end; j++) {
			sorted[k] = v[j];
			localCount++;
			k++;
		}
	}
	for (int i = start; i <= end; i++) {
		v[i] = sorted[i];
	}
}
void mergeSort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, mid, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v.resize(n);
	sorted.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	mergeSort(0, n - 1);
	cout << swapCount << "\n";
	return 0;
}