/*
 * Stack - Data Structure
 *
 *  Created on: 05 Sep 2021
 *      Author: Thomas Corr
 */


#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack_overflow {};
class Stack_underflow {};

class Stack
{
public:
	Stack(int size) : size_{ size }, top_{ -1 }, elem_{ new int[size_] } {};
	~Stack() {delete[] elem_; };
	bool empty();
	void push(int* x);
	int* pop();
private:
	int* elem_;
	int top_;
	int size_;
};


bool Stack::empty() {
	if (top_ < 0) return true;
	return false;
}


void Stack::push(int* x) {
	if (top_ + 1 > size_) throw Stack_overflow();
	top_++;
	elem_[top_] = *x;
}


int* Stack::pop() {
	if (empty()) throw Stack_underflow();
	top_--;
	return &elem_[top_ + 1];
}


#endif // !STACK_H

