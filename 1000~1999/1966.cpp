#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ItemType {
	int priority;
	int order;
};

int main() {
	int num, n, m;
	cin >> num;
	
	while (num--) {
		cin >> n >> m;
		queue<ItemType> q;
		for (int i = 0; i < n; i++) {
			ItemType temp;
			cin >> temp.priority;
			temp.order = i;
			q.push(temp);
		}
		int count = 0;
		while (true) {
			ItemType maxItem;
			maxItem = q.front();
			for (int i = 0; i < q.size(); i++) {
				if (q.front().priority > maxItem.priority) {
					maxItem = q.front();
				}
				q.push(q.front());
				q.pop();
			}
			while (q.front().order != maxItem.order) {
				q.push(q.front());
				q.pop();
			}
			if (q.front().order == m) {
				count++; 
				break;
			}
			else {
				count++;
				q.pop();
			}
		}
		cout << count << "\n";
	}
	
	return 0;
}