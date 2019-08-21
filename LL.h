/*
 * LL.h
 *
 *  Created on: Jun 26, 2019
 *      Author: ddizz
 */

#ifndef LL_H
#define LL_H

#include <iostream>
using namespace std;


// A template class takes in a type in the <>. Look at how we declare a vector
// with: vector<int> thing, there the <int> is the template type.
template <typename T> class LinkedList {
private:
	// private struct for the LL
	struct Node {
		T data;
		Node* next;
		Node* prev;

		Node(): // <- this is called an initializer list, the most common
				// way to write constructors since C++11
			data { T{} },
			next {nullptr},
			prev {nullptr} {};
		explicit Node(const T & _dataMember): // <- the explicit means we
				// can't pass in any extra values to this function or do
				// implicit type casting – important only because this is
				// allowed in C
			data {_dataMember},
			next {nullptr},
			prev {nullptr} {};
		explicit Node(const T && _dataMember):
			data {_dataMember},
			next {nullptr},
			prev {nullptr} {};
	};

	Node* head;	// head pointer: first Node in the LinkedList
	Node* tail; // tail pointer: last Node in the LinkedList
	int size;	// int to keep the size of the list; should be modified
				// as the data structure changes size


	// checks if a given k is within the size of indices in LinkedList
	// returns true if 0 <= k < size,
	// false otherwise
	bool kWithinBounds(int k) const {
		if (k >= 0 && k < size){
			return true;
		}
		return false;
	}

	// will return the kth Node in the LinkedList. This is private
	// because we don't want to support this function for outside
	// classes, this is just for internal usage
	Node* getKthNode(int k) const {
		if (!kWithinBounds(k)) {
			return nullptr;
		}

		Node* cur = head;
		int count = 0;

		while (cur != nullptr) {
			if (k == count) {
				return cur;
			}

			cur = cur -> next;
			count++;
		}

		return nullptr;

	}


public:
	// constructor/destructor
	LinkedList(): 	// default values for LinkedList
		head {nullptr},
		tail {nullptr},
		size {0} {};

	~LinkedList(){	// calls a defined function empty() to clean up all
		// memory in the LinkedList (delete all allocated memory)
		empty();
	}
	// copy constructor -- note that this does a /deep/ copy
	LinkedList (const LinkedList<T> & other):
		head {nullptr}, tail {nullptr}, size {0} {
		Node* temp = other.head;
		while (temp != nullptr){
			this->add(temp->data);
			temp = temp->next;
		}
	}
	// copy assignment operator
	LinkedList& operator= (const LinkedList & other){
		LinkedList copy = other;
		std::swap(*this,copy);
		return *this;
	}

	// move constructor
	LinkedList (LinkedList<T> && other):
		head {other.head}, tail {other.tail}, size {other.size} {
		other.head = other.tail = nullptr;
		other.size = 0;
	}

	// move assignment operator
	LinkedList& operator= (LinkedList<T> && other){
		std::swap(head, other.head);
		std::swap(tail, other.tail);
		std::swap(size, other.size);
		return *this;
	}


	// accessors ----------------------------------------------

	// returns the data stored in the tail Node
	T getHead() const {
		if (head != nullptr){
			return head->data;
		} else {
			return T {};
		}
	}
	// returns the data stored in the tail Node
	T getTail() const {
		if (tail != nullptr){
			return tail->data;
		}

		else {
			return T {};
		}
	}
	// returns the number of nodes in the list.
	int getSize() const {
		return size;
	}

	// will return the index of the item in the list, if it
	// is found. If not, return -1.
	int member(T dataMember) const {
		Node* cur = head;
		int count = 0;


		while (cur != nullptr) {
			if (cur -> data == dataMember) {
				return count;
			}

			else {
				cur = cur -> next;
				count++;
			}

		}

		return -1;  // 	PLACEHOLDER
	}
	// returns the data at index j
	T* findKth(int j) const {
		Node* tmp = getKthNode(j);
		if (!tmp) {
			return nullptr;
		}

		else {
			return &tmp -> data;
		}

		 // PLACEHOLDER
	}

	void printList() const {
		Node* tmp = head;
		std::cout << "[";
		while (tmp != nullptr){
			if (tmp->next != nullptr){
				std::cout << tmp->data << ", ";
			} else {
				std::cout << tmp->data;
			}
			tmp = tmp->next;
		}
		std::cout << "]" << std::endl;
	}


	void printListBackwards() const {
		Node* tmp = tail;
		std::cout << "[";
		while (tmp != nullptr){
			if (tmp->prev != nullptr){
				std::cout << tmp->data << ", ";
			} else {
				std::cout << tmp->data;
			}
			tmp = tmp->prev;
		}
		std::cout << "]" << std::endl;
	}




	// mutators -------------------------------------------------

	// inserts at the first position, replacing the old head pointer
	void insert(const T dataMember) {
		Node* tmp = new Node(dataMember);

		if (head) {
			head -> prev = tmp;
			tmp -> next = head;
		}

		else {
			tail = tmp;
		}

		head = tmp;
		size++;
	}

	// takes a T var called dataMember and makes it the kth
	// value in the list, its next pointing to the node
	// previously at the kth position. If k is out of range, don't
	// insert anything.
	// Note you can never insert at a position outside the
	// size of the list, so no inserting at the end with
	// this function.
	void insertAtK(T dataMember, int k){

		if (k < size && k>= 0) {
			Node* cur = getKthNode(k);
			Node* tmp = new Node(dataMember);

			tmp -> next = cur;
			tmp -> prev = cur -> prev;

			if (cur != head) {
				cur -> prev -> next = tmp;
			}

			else {
				head = tmp;
			}

			cur -> prev = tmp;

			size++;
		}

		else {

			return;
		}
	}


	// insert at the end of the list
	void add(T dataMember){
		Node* temp = new Node(dataMember);
		if (!head){
			head = temp;
			tail = temp;
		} else {
			tail->next = temp;
			temp->prev = tail;
			temp->next = nullptr;
			tail = temp;
		}
		size++;
	}


	// deletes memory at head, sets head to be the prev node, or
	// nullptr if only one node in list.
	void removeHead(){
		if (head != nullptr){
			if (tail == head){ // if only one node
				delete head;
				head = tail = nullptr;
			} else {
				Node* temp = head;
				head = head->next;
				head->prev = nullptr;
				delete temp;
			}
			size--;
		}
	}

	// deletes memory at tail, sets tail to be the prev node, or
	// nullptr if only one node in list.
	void removeTail(){
		if (tail != nullptr) {
			if (tail == head) {
				delete tail;
				head = nullptr;
				tail = nullptr;
			}

			else {
				Node *tmp = tail -> prev;
				tmp -> next = nullptr;
				delete tail;
				tail = tmp;
			}

			size--;
		}
	}

	// removes the kth item in the list
	void removeAtK(int k){
		if (kWithinBounds(k)) {
			Node* cur = getKthNode(k);
			if (cur == head) {
				removeHead();
			}

			else if (cur == tail) {
				removeTail();

			}

			else {
				cur -> prev -> next = cur -> next;
				cur -> next -> prev = cur -> prev;
				delete cur;
				size--;

			}
		}
	}

	// free all memory in the list with delete and reset
	// head, tail and size.
	void empty(){
		while (size != 0) {
			removeHead();
		}
	}

};



#endif /* LL_H_ */
