//cards.h
//Authors: Thao Phan
//All class declarations go here

#include <iostream>
#include <string>
using namespace std;

#ifndef CARDS_H
#define CARDS_H

class Card {
	public:
		Card (string v);
		~Card();
		bool operator== (const Card& other);
		string getValue() const;
		Card* getNext() const;
		Card* getPrevious() const;
		void setValue(string v);
		void setNext(Card *other);
		void setPrevious(Card *other);
		friend std::ostream& operator<< (std::ostream& os, const Card &source);
	private:
		string value;
		Card* next;
		Card* previous;
};

class CardList{
	public:
        	CardList();
		CardList(string v);
        	~CardList();
		Card* getHead() const;
		void print();
		void append(string value);
        	bool remove(string v);
        	bool search(string v) const;
		bool operator==(const CardList& other);

	private:	
		Card* head;
};

#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
