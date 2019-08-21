/*
 * Deque.h
 *
 *  Created on: Jun 26, 2019
 *      Author: ddizz
 */

#ifndef DEQUE_H_
#define DEQUE_H_

#include "LL.h"
using namespace std;


template <typename T> class Deque {
private:
	// using a LinkedList as the storage for this Deque
	LinkedList<T>& data;


public:
	Deque():
		data {*(new LinkedList<T>())} {}


	// accessors -----------------------------------------------------

	LinkedList<T>& getData() const {
		return data;
	}

	// for your testing purposes - should print out each element of
	// the deque without destroying the original deque
	void printDeque() const {
		data.printList();
	}

	// returns the back element
	T getBack() const {
		return data.getTail();
		// PLACEHOLDER FOR COMPILING
	}
	// returns the front element
	T getFront() const {
		return data.getHead();
		// PLACEHOLDER FOR COMPILING
	}

	// inserts element thing at back of Deque
	void pushBack(T thing){
		data.add(thing);
	}

	// inserts element thing at front of Deque
	void pushFront(T thing){
		data.insert(thing);
	}

	// removes element at back of Deque and returns it
	T popBack(){
		if (data.getSize() == 0) {
			return T {};
		}

		else {
			T tmp = data.getTail();
			data.removeTail();
			return tmp;
		}
		// PLACEHOLDER FOR COMPILING
	}

	// removes element at front of Deque and returns it
	T popFront(){
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

};




#endif   //DEQUE_H_
