/*  File:   mySTL.h
	Author: Jake Wagner
	Start:  March 9, 2018
	About:  My personal implementation of some of the c++ STL.


	Table of Contents
	* Functions
		- swap

	* Containers and Organziers
		- Array
		- Node
		- LinkedList
		- DoubleLinkedList
		- Stack
		- Queue
		- BinarySearchTree

	* Iterators
	
	* Algorithms

*/

//FUNCTIONS ===================================================
/*
	swap
	- swaps two items
	@param val1 reference to the first item
	@param val2 reference to the second item
*/
template <class T>
void swap(T val1, T val2) {
	T temp = val1;
	val1 = val2;
	val2 = temp;

	return;
}




//CONTAINERS AND ORGANIZERS ===================================
/*
	Array
	- A fixed size linear contiguous storage container 
*/
template <class T, int size>
class Array<T> {
	public:
		Array(); //default constructor
		Array(T value); //constructor

		int size();
		void fill(T value);
		void swap(Array<T> other);

	private:
		T data[size];
};

//default constructor
template <class T, int size>
Array<T>::Array() {

}//end constructor

//constructor instantaites all items to value
template <class T, int size>
Array<T>::Array(T value) {
	this.fill(value);
}//end constructor

//returns the size of container
template <class T, int size>
int Array::size() {
	return size;
}//end Array<T>::size

//sets every item to value
template <class T, int size>
void Array<T>::fill(T value) {
	for (int i = 0; i < size; ++i)
		data[i] = value;
}//end Array<T>fill

//swaps all items of one Array with another of the same size and type
template <class T, int size>
void Array<T>::swap(Array<T> other) {
	if (other.size == size) {
		for (int i = 0; i < size; ++i) {
			swap(data[i], other.data[i]);
		}
	}
}//end Array<T>::swap





/*
	Node
	- a container object
*/
template <class T>
class Node {
public:
	Node();
	Node(T &newValue);
	~Node();

	T getData() { return this->data; }
	void setData(T &value) { this->data = value; }
	Node* getNext() { return this->next; }
	void setNext(Node *nextNode) { this->next = nextNode; }

private:
	T data;
	Node *next;

};

//default constructor
template <class T>
Node<T>::Node() {
	next = NULL;
}//end constructor

//constructor with data instance
template <class T>
Node<T>::Node(T &newValue) {
	data = newValue;
	next = NULL;
}//end constructor

//destructor
template <class T>
Node<T>::~Node() {
	next = NULL;
}//end destructor





/*
	LinkedList
	- a sinlgely linked list of Node objects
*/





/*
	Queue
	- a FIFO linked list structure
*/
template <class T>
class Queue {
public:
	Queue();
	~Queue();

	bool enqueue(T &value);
	bool dequeue(T &value);
	int getLength() const;
	void list();
	T search(int identifier) const;

private:
	Node<T> *head_;
	Node<T> *tail_;
	int length_;
};

template <class T>
Queue<T>::Queue() {
	head_ = NULL;
	tail_ = NULL;
	length_ = 0;
}//end default constructor

template <class T>
Queue<T>::~Queue() {
	//delete all nodes in queue
	Node<T> *tempNode;
	for (int i = 0; i < length_; ++i) {
		tempNode = head_;
		head_ = head_->getNext();
		delete tempNode;
	}
	//delete queue data
	head_ = tail_ = NULL;
	length_ = 0;
}//end destructor

 /*
 enqueue
 - function to add a value to the end of the queue
 @param value reference to the "value" object for the new node
 @return true if successfuly added new node, false if not
 */
template <class T>
bool Queue<T>::enqueue(T &value) {
	//instantiate new node
	Node<T> *newNode = new Node<T>(value);
	//check if empty queue
	if (length_ == 0) {
		//if empty start queue
		head_ = newNode;
		tail_ = newNode;
	}
	else {
		//else append to queue
		tail_->setNext(newNode);
		tail_ = newNode;
	}
	//count the new node
	++length_;

	return true;
}//end enqueue


 /*
 dequeue
 -  function to remove a value from the begining the queue
 @param value reference for returning the dequeued object
 @return true if successful dequeue, false if not
 the object that was dequeued
 */
template <class T>
bool Queue<T>::dequeue(T &value) {
	//check that the queue is not empty
	if (length_  > 0) {
		//if not empty, save the old head to be dequeued
		Node<T> *tempNode = head_;
		//move the head to the next item
		head_ = head_->getNext();
		if (length_ == 1)
			tail_ = head_->getNext();//NULL if last(only item in queue)
									 //assign the value and delete the dequeued item
		value = tempNode->getData();
		delete tempNode;
		//decrement the count and return
		--length_;
		return true;
	}
	else {
		//else the queue was already empty
		//cout << "Queue is empty\n";
		return false;
	}
}//end dequeue


 /*
 getLength
 - function for getting the lenght of the queue
 return the number of items in the queue
 */
template <class T>
int Queue<T>::getLength() const {
	return this->length_;
}//end getLength




 //ITERATORS ===================================================



 //ALGORITHMS ==================================================






