#include <iostream>
#include "GeneralList.hpp"

template <class T>
class Stack {
	private:
		List<T> _data;
		size_t _size;
		
	public:
		//Default constructor
		Stack() {
			_size = 0;
		}

		//Default copy constructor
		Stack(const Stack &stack) {
			_data = stack._data;
			_size = stack._size;
		}

		//Getters
		T top() const {
			return *(_data + size() - 1);
		}

		size_t size() const {
			return _size;
		}

		//Adding data to the data structure
		void push(T value) {
			_data.push_back(value);
		}
		//Removing data from the data structure
		void pop() {
			_data.pop_back();
		}

		bool search(T value) {
			return _data.search(value);
		}


		bool empty() const {
			if(empty()) 
				return true;
			else
				return false;
		}

		void print() {
			std::cout << *this << std::endl;
		}

		//This overloaded operator is empty, please implement
		Stack<T> operator=(const Stack<T> &stack) {
			stack._data=_data;
			_size=_data._size();
			return *this;
		}

		template <class S>
		friend std::ostream &operator<<(std::ostream &out, const Stack<S> &stack);
		template <class S>
		friend bool operator==(const Stack<S> &left_side, const Stack<S> &right_side);
		template <class S>
		friend bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side);

};

template <class S>
std::ostream &operator<<(std::ostream &out, const Stack<S> &stack) { 
	out << stack._data;
	return out;
}

template <class S>
bool operator==(const Stack<S> &left_side, const Stack<S> &right_side) {
	if(left_side.size() != right_side.size() ) {
		return false;
	}
	for(int i = 0; i < left_side.size(); i++) {
		if(*(left_side._data+i) != *(right_side._data+i)) {
			return false;
		}
	}
	return true;
}
template <class S>
bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side) { 
	return !(left_side==right_side);
}
