CXX_FLAG = --std=c++11 -g

main: main.o cards.o
	g++ $(CXX_FLAG) -o main main.o cards.o

test: testcards.o cards.o
	g++ $(CXX_FLAG) -o test testcards.o cards.o

main.o: main.cpp cards.cpp cards.h
	g++ -c $(CXX_FLAG) main.cpp cards.cpp

testcards.o: testcards.cpp cards.cpp testcards.h cards.h
	g++ -c $(CXX_FLAG) testcards.cpp cards.cpp

cards.o: cards.cpp cards.h
	g++ -c $(CXX_FLAG) cards.cpp

clean:
	rm -f test *.o *.sw
