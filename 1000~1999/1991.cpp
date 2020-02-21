#include <iostream>
#include <vector>

using namespace std;

class Tree {
private:
	vector<int> v[26];
	int size;
public:
	Tree() {
		cin >> size;
		for (int i = 0; i < size; i++) {
			char value, left, right;
			cin >> value >> left >> right;
			v[value - 'A'].push_back(left);
			v[value - 'A'].push_back(right);
		}
	}
	void preorder(char value) {
		if (value != '.') {
			cout << value;
			preorder(v[value - 'A'][0]);
			preorder(v[value - 'A'][1]);
		}
	}
	void inorder(char value) {
		if (value != '.') {
			inorder(v[value - 'A'][0]);
			cout << value;
			inorder(v[value - 'A'][1]);
		}
	}
	void postorder(char value) {
		if (value != '.') {
			postorder(v[value - 'A'][0]);
			postorder(v[value - 'A'][1]);
			cout << value;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Tree t;
	t.preorder('A');
	cout << "\n";
	t.inorder('A');
	cout << "\n";
	t.postorder('A');
	cout << "\n";
	return 0;
}