#pragma once
#include<iostream>
using namespace std;
//------------------------------------------------
//  class List
//------------------------------------------------
class List
{
private:
	//--------------------------------------------
	//  class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		// data fields
		int value;
		Link* next;

	};
public:
	// constructors
	List();
	List(const List&);
	~List();
	List& operator=(const List& rhs);
	List(List&& source);
	List& operator=(List&& rhs);

	// operations
	void add(int value);
	int firstElement() const;
	bool search(int value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	void insert(int key);
	void remove(int key);
	friend ostream& operator<<(ostream& lhs, List& rhs);

private:
	// data field
	Link* head;
};
