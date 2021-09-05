#ifndef CYCLICQUEUE_H
#define CYCLICQUEUE_H

#include <iostream>

class CyclicQueue
{
public:
	CyclicQueue(int maxSize); // Constructor, initialising maxBufferSize
	~CyclicQueue(); // Destructor
	void addAtEnd(int i); // Adds item to end of queue, if room
	int* removeFront(); // Returns pointer to front item, and removes it
	int* getAtFront(); // Returns pointer to front item, but doesn’t remove it
	bool isEmpty(); // Returns true if the queue is currently empty
	int size(); // Returns the number of items in the queue
private:
	int maxBufferSize; // Maximum size of the array
	int* buffer; // The array (buffer) itself
	int first, last; // Positions of the first and last items in the buffer
	int numItems; // Number of items currently in the buffer
};

CyclicQueue::CyclicQueue(int maxSize) {
	maxBufferSize = maxSize;
	if (maxSize <= 0) {
		std::cout << "Buffer size error: " << maxSize << std::endl;
		buffer = NULL;
		return;
	}
	buffer = new int[maxBufferSize];
	first = 0;
	last = maxBufferSize - 1;
	numItems = 0;
}

CyclicQueue::~CyclicQueue() {
	delete[] buffer;
}

void CyclicQueue::addAtEnd(int i) {
	if (last == first) {
		std::cout << "Buffer full" << std::endl;
		return;
	}
	last = (last + 1) % maxBufferSize;
	buffer[last] = i;
	numItems++;
}

int* CyclicQueue::removeFront() {
	if (numItems <= 0) {
		std::cout << "Cannot remove front of empty buffer" << std::endl;
		return NULL;
	}
	int* value = &buffer[first];
	first = (first + 1) % maxBufferSize;
	numItems--;
	return value;
}

int* CyclicQueue::getAtFront() {
	if (numItems <= 0) {
		std::cout << "Cannot get front of empty buffer" << std::endl;
		return NULL;
	}
	return &buffer[first];
}

bool CyclicQueue::isEmpty() {
	return numItems == 0;
}

int CyclicQueue::size() {
	return numItems;
}

#endif // !CYCLICQUEUE_H
