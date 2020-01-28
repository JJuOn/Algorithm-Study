#include <iostream>
#include <string>

using namespace std;

void quickSort(string words[], int left, int right) {
	if (left >= right) {
		return;
	}
	int i = left - 1;
	int j = left;
	int pivot = right;
	for (; j < right; j++) {
		if (words[j].length() < words[pivot].length()) {
			string temp;
			i++;
			temp = words[j];
			words[j] = words[i];
			words[i] = temp;
		}
		else if (words[j].length() == words[pivot].length() && words[j] < words[pivot]) {
			string temp;
			i++;
			temp = words[j];
			words[j] = words[i];
			words[i] = temp;
		}
	}
	string temp;
	i++;
	temp = words[pivot];
	words[pivot] = words[i];
	words[i] = temp;

	quickSort(words, left, i - 1);
	quickSort(words, i + 1, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, size, count = 0;
	string* words;
	cin >> n;
	words = new string[n];
	size = n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		bool found = false;
		for (int j = 0; j < i; j++) {
			if (temp == words[j]) {
				size--;
				found = true;
			}
		}
		if (!found) {
			words[count++] = temp;
		}
	}
	quickSort(words, 0, size - 1);
	for (int i = 0; i < size; i++) {
		cout << words[i] << "\n";
	}
	return 0;
}