/*
 * Stack.h
 *
 *  Created on: Jun 26, 2019
 *      Author: ddizz
 */

#ifndef STACK_H_
#define STACK_H_

#include "LL.h"

template <typename T> class Stack {
private:
	// using a LinkedList as the storage for this Stack
	LinkedList<T> & data;

public:
	// constructor
	Stack ():
		data {*(new LinkedList<T>())} {}

	// accessors -----------------------------------------------------

	// returns a copy of the pointer to the local data variable
	LinkedList<T>& getData() const {
		return data;
	}

	void printStack() const {
		data.printList();
	}

	// return first element of stack without removing
	T peek() const {
		return data.getHead(); //PLACEHOLDER FOR COMPILING
	}

	// mutators ------------------------------------------------------

	// remove the element off the top of the stack and return it. If
	// the stack is empty, return the empty constructor for type T.
	T pop(){
		if (data.getSize() == 0) {
			return T {};
		}

		else {
			T tmp = data.getHead();
			data.removeHead();
			return tmp;
		}
		// PLACEHOLDER FOR COMPILING
	}

	// push item thing of type T onto the stack
	void push(T thing) {
		data.insert(thing);
	}


};



#endif /* STACK_H_ */
