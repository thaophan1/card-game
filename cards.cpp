//cards.cpp
//Authors: Thao Phan
//Implementation of the classes defined in cards.h

#include <iostream>
#include <string>
#include "cards.h"

using namespace std;

Card::Card(string v) {
    	value = v;
    	next = nullptr;
	previous = nullptr;
}

Card::~Card() {
    	delete next;
}

bool Card::operator==(const Card& other) {
	if (other.value == value) {
		return true;
	}
	return false;
}

string Card::getValue() const {
	return value;
}

Card* Card::getNext() const {
	return next;
}

Card* Card::getPrevious() const {
	return previous;
}

void Card::setValue(string v) {
	value = v;
}

void Card::setNext(Card *other) {
	next = other;
}

void Card::setPrevious(Card *other) {
	previous = other;
}

std::ostream& operator<< (std::ostream& os, const Card& source) {
	os << source.value;
	return os;
}

//CardList functions

CardList::~CardList() {
	delete head;
}

CardList::CardList() {
    	head = nullptr;
}

CardList::CardList(string v) {
	Card *c = new Card(v);
	head = c;
}

Card* CardList::getHead() const {
	return head;
}

void CardList::print() {
	Card *p = head;
	while (p) {
		cout << *p << endl;
		p = p->getNext();
	}
	return;
}

void CardList::append(string value) {
    	Card *p = head;
    	Card *n = new Card(value);
    	if (head == nullptr) {
        	head = n;
		return;
    	}
    	while (p->getNext()) {
        	p = p->getNext();
    	}
    	p->setNext(n);
    	n->setPrevious(p);
}   	 

bool CardList::search(string v) const{
    	Card *p = head;
    	while(p) {
        	if (p->getValue() == v) {
            	return true;
        	}
		p = p->getNext();
    	}
    	return false;
}

bool CardList::operator==(const CardList& other) {
	Card* p = head;
	Card* o = other.head;
	while (p && o) {
		if (!other.search(p->getValue())) {
			return false;
		}
		p = p->getNext();
		o = o->getNext();
	}
	if (p || o) {
		return false;
	}
	return true;
}

bool CardList::remove(string v) {
	if (search(v)) {
		Card *c = head;
		if (c->getValue() == v) {
			head = c->getNext();
			c->setNext(nullptr);
			delete c;
			return true;
		}
		c = c->getNext();
		while (c) {
			if (c->getValue() == v) {
				if (c->getPrevious() && c->getNext()) {
					Card* p = c->getPrevious();
					Card* n = c->getNext();
					p->setNext(n);
					n->setPrevious(p);
					c->setNext(nullptr);
					delete c;
					return true;
				}
				if (c->getNext() == nullptr) {
					Card *p = c->getPrevious();
					p->setNext(nullptr);
					delete c;
					return true;
				}
			} else {
				c = c->getNext();
			}
		}
	}
	return false;
}
