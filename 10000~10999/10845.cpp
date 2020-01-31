#include <iostream>
#include <string>

#define MAX_SIZE 10000

using namespace std;

class Queue {
private:
	int m_front;
	int m_rear;
	int m_data[MAX_SIZE + 1];
public:
	Queue();
	void push(const int x);
	void pop();
	int size();
	bool empty();
	void front();
	void back();
};

Queue::Queue() {
	this->m_front = 0;
	this->m_rear = 0;
}

void Queue::push(const int x) {
	this->m_data[this->m_rear] = x;
	this->m_rear = (this->m_rear + 1) % MAX_SIZE;
}

void Queue::pop() {
	if (this->m_front == this->m_rear) {
		cout << -1 << "\n";
	}
	else {
		cout << this->m_data[this->m_front] << "\n";
		this->m_front = (this->m_front + 1) % MAX_SIZE;
	}
}

int Queue::size() {
	int tempSize = this->m_rear - this->m_front;
	if (tempSize >= 0) {
		cout << tempSize << "\n";
		return tempSize;
	}
	else {
		cout << MAX_SIZE - tempSize << "\n";
		return MAX_SIZE - tempSize;
	}
}

bool Queue::empty() {
	if (this->m_front==this->m_rear) {
		cout << 1 << "\n";
		return true;
	}
	else {
		cout << 0 << "\n";
		return false;
	}
}

void Queue::front() {
	if (this->m_front == this->m_rear) {
		cout << -1 << "\n";
	}
	else {
		cout << this->m_data[this->m_front] << "\n";
	}
}

void Queue::back() {
	if (this->m_front == this->m_rear) {
		cout << -1 << "\n";
	}
	else {
		cout << this->m_data[(this->m_rear-1)%MAX_SIZE] << "\n";
	}
}
int main() {
	int n, opr2;
	cin >> n;
	string opr1;
	Queue q;
	while (n--) {
		cin >> opr1;
		if (opr1 == "push") {
			cin >> opr2;
			q.push(opr2);
		}
		else if (opr1 == "pop") {
			q.pop();
		}
		else if (opr1 == "size") {
			q.size();
		}
		else if (opr1 == "empty") {
			q.empty();
		}
		else if (opr1 == "front") {
			q.front();
		}
		else if (opr1 == "back") {
			q.back();
		}
	}
	return 0;
}