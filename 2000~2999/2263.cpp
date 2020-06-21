#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inorder, postorder;
int n;

void func(int postorderRootIndex, int inorderStart, int inorderEnd) {
	cout << postorder[postorderRootIndex] << " ";
	if (inorderStart >= inorderEnd) {
		return;
	}
	else {
		int inorderRootIndex, leftRoot, rightRoot, leftSize, rightSize;
		for (int i = inorderStart; i <= inorderEnd; i++) {
			if (inorder[i] == postorder[postorderRootIndex]) {
				inorderRootIndex = i;
				break;
			}
		}
		leftSize = inorderRootIndex - inorderStart;
		rightSize = inorderEnd - inorderRootIndex;
		if (leftSize > 0) {
			func(postorderRootIndex - rightSize - 1, inorderStart, inorderRootIndex - 1);
		}
		if (rightSize > 0) {
			func(postorderRootIndex - 1, inorderRootIndex + 1, inorderEnd);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	inorder.resize(n);
	postorder.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
	func(n - 1, 0, n - 1);
	cout << "\n";
	return 0;
}