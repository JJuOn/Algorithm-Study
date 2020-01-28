#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct UserType {
	int age;
	char name[101];
};

UserType temp[100000];

void merge(UserType* users, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (users[i].age <= users[j].age) {
			temp[k].age = users[i].age;
			strcpy(temp[k].name,users[i].name);
			i++;
		}
		else {
			temp[k].age = users[j].age;
			strcpy(temp[k].name,users[j].name);
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int l = j; l <= right; l++) {
			temp[k].age = users[l].age;
			strcpy(temp[k].name,users[l].name);
			k++;
		}
	}
	else {
		for (int l = i; l <= mid; l++) {
			temp[k].age = users[l].age;
			strcpy(temp[k].name, users[l].name);
			k++;
		}
	}
	for (int m = left; m <= right; m++) {
		users[m].age = temp[m].age;
		strcpy(users[m].name,temp[m].name);
	}
}

void mergeSort(UserType users[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(users, left, mid);
		mergeSort(users, mid + 1, right);
		merge(users, left, mid, right);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	UserType* users;
	cin >> n;
	users = new UserType[n];
	for (int i = 0; i < n; i++) {
		cin >> users[i].age >> users[i].name;
	}
	mergeSort(users, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << users[i].age << " " << users[i].name << "\n";
	}
	delete[] users;
	return 0;
}