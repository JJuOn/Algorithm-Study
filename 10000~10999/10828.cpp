#include <iostream>
#include <string>

#define MAX_SIZE 10000

using namespace std;

class Stack {
private:
	int m_data[MAX_SIZE];
	int m_top;
public:
	Stack();
	void push(int x);
	void pop();
	void size();
	void empty();
	void top();
};

Stack::Stack() {
	this->m_top = -1;
}

void Stack::push(int x) {
	this->m_top++;
	this->m_data[this->m_top] = x;
}

void Stack::pop() {
	if (this->m_top == -1) {
		cout << -1 << "\n";
	}
	else {
		cout << this->m_data[this->m_top] << "\n";
		this->m_top--;
	}
}

void Stack::size() {
	cout << this->m_top + 1 << "\n";
}

void Stack::empty() {
	if (this->m_top == -1) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}

void Stack::top() {
	if (this->m_top == -1) {
		cout << -1 << "\n";
	}
	else {
		cout << this->m_data[this->m_top] << "\n";
	}
}

int main() {
	int n, opr2;
	cin >> n;
	string opr1;
	Stack s;
	while (n--) {
		cin >> opr1;
		if (opr1 == "push") {
			cin >> opr2;
			s.push(opr2);
		}
		else if (opr1 == "pop") {
			s.pop();
		}
		else if (opr1 == "size") {
			s.size();
		}
		else if (opr1 == "empty") {
			s.empty();
		}
		else if (opr1 == "top") {
			s.top();
		}
	}
	return 0;
}