C++_Q_FNS = GeneralQueue.hpp
C++_S_FNS = GeneralStack.hpp
C++_MAIN = main.cpp

all:
	g++ $(C++_Q_FNS) $(C++_S_FNS) $(C++_MAIN) -o test

run:	
	g++ $(C++_Q_FNS) $(C++_S_FNS) $(C++_MAIN) -o test
	./test

clean:
	rm test
