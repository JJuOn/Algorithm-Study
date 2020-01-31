#include <iostream>
#include <string>
#include <queue>

#define MAX_SIZE 5000

using namespace std;

class Queue {
private:
	int m_data[MAX_SIZE + 1];
	int m_front;
	int m_rear;
	int m_size;
public:
	Queue();
	void push(int x);
	void pop();
	int front();
};

Queue::Queue() {
	m_front = m_rear = 0;
}

void Queue::push(int x) {
	m_data[m_rear] = x;
	m_rear = (m_rear + 1) % MAX_SIZE;
	m_size++;
}

void Queue::pop() {
	if (m_size != 0) {
		m_front = (m_front + 1) % MAX_SIZE;
		m_size--;
	}
}

int Queue::front() {
	return m_data[m_front];
}
int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << "<";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		if (i != n - 1) {
			cout << q.front()<<", ";
			q.pop();
		}
		else {
			cout << q.front() << ">\n";
			q.pop();
		}
	}
	return 0;
}