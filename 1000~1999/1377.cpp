#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct ItemType {
	int num;
	int firstIndex;
};

bool CustomCompare(ItemType item1, ItemType item2) {
	return item1.num < item2.num;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	vector<ItemType> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ItemType temp;
		cin >> temp.num;
		temp.firstIndex = i;
		v.push_back(temp);
	}
	stable_sort(v.begin(), v.end(), CustomCompare);
	int maxDiff=-1;
	for (int i = 0; i < v.size(); i++) {
		int currentDiff = v[i].firstIndex - i;
		if (currentDiff > maxDiff) {
			maxDiff = currentDiff;
		}
	}
	cout << maxDiff + 1 << "\n";
	return 0;
}
