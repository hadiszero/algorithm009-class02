// 641. Design Circular Deque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
private:
	vector<int> m_iaArr;
	int m_iFront;
	int m_iRear;
	int m_iCapacity;

public:
	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k) {
		m_iCapacity = k + 1;
		m_iaArr.assign(m_iCapacity, 0);

		m_iFront = 0;
		m_iRear = 0;
	}

	/** Adds an item at the m_iFront of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (isFull()) {
			return false;
		}
		m_iFront = (m_iFront - 1 + m_iCapacity) % m_iCapacity;
		m_iaArr[m_iFront] = value;
		return true;
	}

	/** Adds an item at the m_iRear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (isFull()) {
			return false;
		}
		m_iaArr[m_iRear] = value;
		m_iRear = (m_iRear + 1) % m_iCapacity;
		return true;
	}

	/** Deletes an item from the m_iFront of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (isEmpty()) {
			return false;
		}
		m_iFront = (m_iFront + 1) % m_iCapacity;
		return true;
	}

	/** Deletes an item from the m_iRear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (isEmpty()) {
			return false;
		}
		m_iRear = (m_iRear - 1 + m_iCapacity) % m_iCapacity;
		return true;
	}

	/** Get the m_iFront item from the deque. */
	int getFront() {
		if (isEmpty()) {
			return -1;
		}
		return m_iaArr[m_iFront];
	}

	/** Get the last item from the deque. */
	int getRear() {
		if (isEmpty()) {
			return -1;
		}
		return m_iaArr[(m_iRear - 1 + m_iCapacity) % m_iCapacity];
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return m_iFront == m_iRear;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		return (m_iRear + 1) % m_iCapacity == m_iFront;
	}
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main()
{
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
