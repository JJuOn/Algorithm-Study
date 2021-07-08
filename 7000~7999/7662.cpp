#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class DoubleEndedPriorityQueue {
private:
	multiset<int,greater<int>> s;
public:
	void insert(int n) {
		s.insert(n);
		return;
	}
	int getMax() {
		return *(s.begin());
	}
	int getMin() {
		return *(s.rbegin());
	}
	void deleteMax() {
		if (s.size() == 0) {
			return;
		}
		else {
			s.erase(s.begin());
			return;
		}
	}
	void deleteMin() {
		if (s.size() == 0) {
			return;
		}
		else {
			multiset<int, greater<int>>::iterator it = s.end();
			it--;
			s.erase(it);
			return;
		}
	}
	bool empty() {
		return s.size() == 0;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int k;
		DoubleEndedPriorityQueue depq;
		cin >> k;
		while (k--) {
			char opr1;
			cin >> opr1;
			if (opr1 == 'D') {
				int opr2;
				cin >> opr2;
				if (opr2 == 1) {
					depq.deleteMax();
				}
				else {
					depq.deleteMin();
				}
			}
			else if (opr1 == 'I') {
				int opr2;
				cin >> opr2;
				depq.insert(opr2);
			}
		}
		if (depq.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << depq.getMax() << " " << depq.getMin() << "\n";
		}
	}
	return 0;
}