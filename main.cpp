#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
	CardList alice;
	CardList bob;
  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
  	alice.append(line);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
  	bob.append(line);
  }
  cardFile2.close();

  // Start the game
  	Card *a = alice.getHead();
	Card *b = bob.getHead();
	Card *atemp, *btemp;
	while (a && b) {
		while(a) {
			if (bob.search(a->getValue())) {
				cout << "Alice picked matching card " << *a << endl;
				atemp = a->getPrevious();
				alice.remove(a->getValue());
				bob.remove(a->getValue());
				a = atemp;
				break;
			} else {
				a = a->getNext();
			}
		}
		while (b) {
			if (alice.search(b->getValue())) {
				cout << "Bob picked matching card " << *b << endl;
				btemp = b->getPrevious();
				alice.remove(b->getValue());
				bob.remove(b->getValue());
				b = btemp;
				break;
			} else {
				b = b->getNext();
			}
		}
	}
	cout << endl;
	cout << "Alice's cards:" << endl;
	alice.print();
	
	cout << endl;
	cout << "Bob's cards:" << endl;
	bob.print();
  return 0;
}
