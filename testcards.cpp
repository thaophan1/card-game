// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  	runAll();
  	return 0;
}

void runAll(){
  test_search();
  test_append();
  test_equal();
  test_card();
  test_print();
  test_remove();
}

void test_search() {
	cout << endl;
	START_TEST("test_search");
	test_search_empty_list();
	test_search_one_element_list();
	test_search_loaded_list();
	END_TEST("test_search");
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  test_equal_single_element_list();
  test_equal_loaded_element_list();
  END_TEST("test_equal");
}


void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  END_TEST("test_card");
}

void test_remove() {
	CardList c1;
	string cards[5] = {"7 d", "j s", "k h", "a c", "0 h"};
	for (int i = 0; i < 5; i++) {
		c1.append(cards[i]);
	}
	
	START_TEST("test_remove");
	test_remove_head(c1);
	test_remove_tail(c1);
	test_remove_middle(c1);
	END_TEST("test_remove");
}

void test_print() {
	START_TEST("test_print");
	cout << "print single card" << endl;
	test_print_card();
	cout << "print CardList" << endl;
	test_print_list();
	END_TEST("test_print");
}

void test_search_empty_list() {
	CardList c;
	assertEquals(false, c.search("3 h"), "case 0: empty list");
}

void test_search_one_element_list() {
	CardList c1("2 d");
	assertEquals(true, c1.search("2 d"), "case 1: one element list");
	assertEquals(false, c1.search("a h"), "case 2: one element list");
}

void test_search_loaded_list() {
	CardList c2;
	string cards[3] = {"a d", "5 h", "k s"};
	for (int i = 0; i < 3; i++) {
		c2.append(cards[i]);
	}
	assertEquals(true, c2.search("5 h"), "case 3: loaded element list");
	assertEquals(false, c2.search("k d"), "case 4: loaded element list");
}

void test_append_empty_list(){ 
// A test case for append single card node to LinkedList
	CardList actual;
	CardList expected("j h");
	actual.append("j h");
	string testName = "case 0: append empty list";
	assertEquals(expected.getHead()->getValue(), actual.getHead()->getValue(), testName); 
}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
	CardList c1("a h");
	string cards[3] = {"0 c", "2 s", "q h"};
	for (int i = 0; i < 3; i++) {
		c1.append(cards[i]);
	}
	assertEquals(true, c1.search("0 c"), "case 1: append 10 c");
	assertEquals(true, c1.search("q h"), "case 2: append q h");
	c1.print();
    // small, fast, orthogonal (test for different cases)

}
void test_equal_empty_list(){ 
  string testname = "case 0: empty list";
  CardList l1, l2;
  assertEquals(true, l1 == l2, testname);
}

void test_equal_single_element_list() {
	CardList c1("2 h");
	CardList c2("a d");
	CardList c3("a d");
	assertEquals(true, c2 == c3, "case 1: ['a d'] = ['a d']");
	assertEquals(false, c1 == c3, "case 2: ['2 h'] != ['a d']");
}

void test_equal_loaded_element_list() {
	CardList c1;
	string cards[5] = {"7 d", "j s", "k h", "a c", "0 h"};
	for (int i = 0; i < 5; i++) {
		c1.append(cards[i]);
	}
	CardList c2;
	string cards2[5] = {"7 d", "a c", "k h", "j s", "0 h"};
	for (int i = 0; i < 5; i++) {
		c2.append(cards[i]);
	}
	assertEquals(true, c1 == c2, "case 3: ['7 d', 'j s', 'k h', 'a c', '0 h'] == ['7 d', 'a c', 'k h', 'j s', 10 h'");
	c2.append("9 s");
	assertEquals(false, c1 == c2, "case 4: ['7 d', 'j s', 'k h', 'a c', '0 h'] != ['7 d', 'a c', 'k h', 'j s', 10 h', '9 h'");
}

void test_card_operator_double_equal(){
  // Test to check if == is overloaded for card
	
	Card c1("2 d");
	Card c2("a h");
	Card c3("2 d");
	assertEquals(true, c1 == c3, "case 1: Card == operator '2 d' == '2 d'");
	assertEquals(false, c1 == c2, "case 2: Card == operator '2 d' != 'a h'");
	
}

void test_remove_head(CardList &source) {
	cout << "\n";
	source.print();
	assertEquals(true, source.remove("7 d"), "case 0: removing head");
	source.print();
	cout << "\n";
}

void test_remove_tail(CardList &source) {
	source.print();
	assertEquals(true, source.remove("0 h"), "case 1: removing tail");
	source.print();
	cout <<"\n";
}

void test_remove_middle(CardList &source) {
	source.print();
	assertEquals(true, source.remove("k h"), "case 2: removing middle");
	source.print();
	cout << "\n";
}

void test_print_card() {
	Card c1("8 h");
	cout << c1 << endl;
}

void test_print_list() {
	CardList c1;
	string cards[5] = {"7 d", "j s", "k h", "a c", "0 h"};
	for (int i = 0; i < 5; i++) {
		c1.append(cards[i]);
	}
	Card *p = c1.getHead();
	while (p) {
		cout << *p << endl;
		p = p->getNext();
	}
}
