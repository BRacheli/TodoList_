#include "List.h"
#include <iostream>
//129:
//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}


//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(nullptr)
{

}

List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head->next;
		trg = head;
		while (src != nullptr)
		{
			trg->next = new Link(src->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}

List::~List()
{
	clear();
}

List& List::operator=(const List& rhs) {
	if (!isEmpty())
		clear();
	Link *src=new Link(rhs.head->value, rhs.head->next),*trg;
	head = new Link(src->value,nullptr);
	src = src->next;
	trg = head;
	while (src!=nullptr)
	{
		trg->next = new Link(src->value, nullptr);
		src = src->next;
		trg = trg->next;
	}
	return *this;
}

List::List(List&& source) {
	head = source.head;
	source.head = nullptr;
}

List& List::operator=(List&& rhs) {
	if (!isEmpty())
		clear();
	head = rhs.head;
	rhs.head = nullptr;
	return *this;
}

void List::clear()
{
	// empty all elements from the List
	Link* next;
	for (Link* p = head; p != nullptr; p = next)
	{
		next = p->next;
		delete p;
	}
	head = nullptr;
}

bool List::isEmpty() const
{
	return head == nullptr;
}

void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool  List::search(int val) const
{
	// search val in List
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}

void List::removeFirst()
{
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	Link* p = head;
	head = p->next;
	delete p;
}

void List::insert(int key) {
	Link* temp = head, * prev = head,*newLink= new Link(key, nullptr);
	if (isEmpty()) {
		head=new Link(key,nullptr);
		return;
	}
	//if we have to put this new value(key) at first place
	if (!(key < temp->value)) {
		head = new Link(key, temp);
		return;
	}
	temp = temp->next;
	while (temp != nullptr) {
		if (key < temp->value) {
			prev = temp;
			temp = temp->next;
		}			
		else {
			newLink->next= temp;
			prev->next = newLink;
			return;
		}
	}
	prev->next = newLink;
}

void List::remove(int key) {
	if (isEmpty()) {
		cout << "value not found" << endl;
		return;
	}
	
	Link* temp=head, *prev=head;
	if (temp->value == key) {
		head = temp->next;
		return;
	}
	temp = temp->next;
	while (temp != nullptr) {
		if (temp->value == key) {
			prev->next = temp->next;
			delete temp;
			return;
		}
		else {
			prev = temp;
			temp = temp->next;
		}
	}
	cout << "value not found" << endl;
}

ostream& operator<<(ostream& lhs, List& rhs) {
	List::Link* temp = rhs.head;
	lhs << "values: ";
	while (temp != nullptr) {
		lhs << temp->value << " ";
		temp = temp->next;
	}
	lhs << endl;
	return lhs;
}
