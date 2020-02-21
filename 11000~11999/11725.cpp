#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];
int parent[100001] = { 0 };

class Tree {
private:
	int size;
public:
	int root;
	Tree() {
		cin >> size;
		for (int i = 0; i < size - 1; i++) {
			int node1, node2;
			cin >> node1 >> node2;
			v[node1].push_back(node2);
			v[node2].push_back(node1);
		}
	}
	void makeParent() {
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int i = 0; i < v[node].size(); i++) {
				if (parent[v[node][i]] == 0) {
					q.push(v[node][i]);
					parent[v[node][i]] = node;
				}
			}
		}
	}
	void printParent() {
		for (int i = 2; i <= size; i++) {
			cout << parent[i] << "\n";
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Tree t;
	t.makeParent();
	t.printParent();
	return 0;
}