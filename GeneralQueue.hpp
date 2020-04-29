#include <iostream>
//Do not include GeneralList.hpp because 
//	GeneralStack.hpp already includes it
template <class Q>
class Queue {
	private:
		List<Q> _data;
		size_t _size;
	public:
		//Default constructor
		Queue() {
				_size = 0;
				_data = nullptr;
		}

		//Copy constructor
		Queue(const List<Q> &q){
				if(q.size() == 0) {
						_size = 0;
						_data = nullptr;
				}
				else {
					int q_size = q.size();
					List<Q> *q_values_copy = new List<Q>[q_size];
					int i;
					for(i=0; i<q_size; i++) {
							*(q_values_copy+i) = *(q._data+i);
					}
					
					if(q_size == 1) {
							_data = new List<Q>(*q_values_copy);
					}
					else {
						_data = new List<Q>[q_size];
						for(i=0; i<q_size; i++) {
								*(_data+i) = *(q_values_copy+i);
						}
					}
						_size = q_size;
						delete [] q_values_copy;
				}
		}

		//Getters
		size_t size() const {
			return _size;	
		}

		Q front() const {
			return *_data;
		}

		Q back() const {
			return *(_data + size() - 1);
		}

		//Push to queue
		void enqueue(Q value) {
				_data.push_front(value);
				_size = _data._size();
		}

		//Pop from queue
		void dequeue() {
				_data.pop_back();
		}

		void print() {
			std::cout << *this << std::endl;
		}

		bool search(Q value) {
				return _data.search(value);
		}

		bool empty() const {
			if(empty())
				return true;
			else
				return false;
		}

		Queue<Q> operator=(const Queue<Q> q) {
			_data = q._data;
			_size = _data.size();
			return *this;
		}

		template <class U>
		friend std::ostream &operator<<(std::ostream &out, 
				const Queue<U> &q);

		template <class U>
		friend bool operator==(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);

		template <class U>
		friend bool operator!=(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);
};
/*
template <class U>
std::ostream &operator<<(std::ostream &out, const Queue<U> &q) {
	out << queue._data;
	return out;
}
template <class U>		
bool operator==(const Queue<U> &left_queue, const Queue<U> &right_queue) {
	if(left_queue.size() != right_queue.size() ) {
		return false;
	}
	for(int i = 0; i < left_side.size(); i++) {
		if(*(left_side._data+i) != *(right_side._data+i)) {
			return false;
		}
	}
	return true;
}
*/
