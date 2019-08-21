/*
 * main.cpp
 *
 *  Created on: Jun 26, 2019
 *      Author: ddizz
 */


// stdlib includes
#include <iostream>
#include <cassert>
// local includes
#include "LL.h"
#include "Stack.h"
#include "Deque.h"


template <typename T>
void testLinkedList() {
	LinkedList<T> testing {};
	// testing add
	testing.add(T{4});
	testing.add(T{7});
	testing.add(T{1});
	testing.add(T{9});
	testing.add(T{2});

	assert (testing.getSize() == 5);
	assert (testing.getHead() == 4);
	assert (testing.getTail() == 2);

	// testing member
	assert (testing.member(7) == 1);
	assert (testing.member(2) == 4);
	assert (testing.member(15) == -1); // not in list

	// testing empty
	testing.empty();
	assert (testing.getSize() == 0);

	// testing insert
	testing.insert(T{4});
	testing.insert(T{7});
	testing.insert(T{1});
	testing.insert(T{9});
	assert (testing.getSize() == 4);
	assert (testing.getHead() == 9);
	assert (testing.getTail() == 4);

	// testing findKth
	assert (testing.findKth(2) &&
			*testing.findKth(2) == 7);
	assert (!testing.findKth(4)); // out of bounds


	testing.insertAtK(3,1); // insert 3 at position 1
	testing.insertAtK(8,4); // insert 8 at position 4
	assert (*testing.findKth(1) == 3);
	assert (testing.getSize() == 6);

	// testing remove head/remove tail
	testing.removeHead();
	assert (testing.getHead() == 3);
	assert (testing.getSize() == 5);
	testing.removeTail();
	assert (testing.getTail() == 8);
	assert (testing.getSize() == 4);

	// testing removeAtK
	testing.removeAtK(1);
	assert (testing.getSize() == 3);
	assert (testing.getHead() == 3);
	testing.removeAtK(0);
	assert (testing.getSize() == 2);
	assert (testing.getHead() == 7);

	//testing.printList();
}

template <typename T>
void testStack() {
	Stack<T> testing {};

	assert (testing.getData().getSize() == 0);
	testing.push(5);
	assert (testing.getData().getSize() == 1);
	assert (testing.peek() == 5);
	assert (testing.pop() == 5);
	assert (testing.getData().getSize() == 0);
	assert (!testing.peek());	// should be 0 (default)

	testing.push(1);
	testing.push(6);
	testing.push(3);
	testing.push(9);
	testing.push(7);
	assert (testing.getData().getSize() == 5);

}

template <typename T>
void testDeque() {
	// use this to test Deque
	Deque<T> testing {};

	assert (testing.getData().getSize() == 0);
	testing.pushBack(3);
	testing.pushBack(8);
	testing.pushBack(1);
	testing.pushBack(9);
	assert (testing.getData().getSize() == 4);
	assert (testing.getBack() == 9);
	assert (testing.getFront() == 3);

	testing.popBack();
	assert (testing.getBack() == 1);
	testing.popFront();
	assert (testing.getFront() == 8);
	assert (testing.getData().getSize() == 2);


}


int main(int argc, char* argv[]){
	testLinkedList<float>();
	testStack<float>();
	testDeque<float>();


	std::cout << "finished all tests" << std::endl;
}
