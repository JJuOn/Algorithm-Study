#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Tree {
private:
	vector<int> v[10001];
	vector<int> nodeList;
	int parent[10001] = {0};
	int levelList[10001];
	int size;
	int maxLevel = 0;
public:
	int root;
	Tree() {
		cin >> size;
		for (int i = 0; i < size; i++) {
			int value, left, right;
			cin >> value >> left >> right;
			v[value].push_back(left);
			if (left != -1) {
				parent[left] = value;
			}
			v[value].push_back(right);
			if (right != -1) {
				parent[right] = value;
			}
		}
	}
	void makeNodeList(int node) {
		if (node != -1) {
			makeNodeList(v[node][0]);
			nodeList.push_back(levelList[node]);
			makeNodeList(v[node][1]);
		}
	}
	void findMaxWidth() {
		int maxWidth = 1, at = 1;
		for (int i = 1; i <= maxLevel; i++) {
			int index1, index2;
			for (int j = 0; j < size; j++) {
				if (nodeList[j] == i) {
					index1 = j;
					break;
				}
			}
			for (int j = size-1; j >= 0; j--) {
				if (nodeList[j] == i) {
					index2 = j;
					break;
				}
			}
			int width = index2 - index1 + 1;
			if (width > maxWidth) {
				maxWidth = width;
				at = i;
			}
		}
		cout << at << " " << maxWidth << "\n";
	}
	void findRoot() {
		for (int i = 1; i <= size; i++) {
			if (parent[i] == 0) {
				root = i;
				break;
			}
		}
	}
	void makeLevelList(int i, int level) {
		if (i != -1) {
			levelList[i] = level;
			if (level > maxLevel) {
				maxLevel = level;
			}
			makeLevelList(v[i][0], level + 1);
			makeLevelList(v[i][1], level + 1);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Tree t;
	t.findRoot();
	t.makeLevelList(t.root, 1);
	t.makeNodeList(t.root);
	t.findMaxWidth();
	return 0;
}