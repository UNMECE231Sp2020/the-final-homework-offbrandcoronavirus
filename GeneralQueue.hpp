#include <iostream>
//Do not include GeneralList.hpp because 
//	GeneralStack.hpp already includes it
/*#include "GeneralList.hpp"*/

template <class Q>
class Queue {
	private:
		List<Q> _data;
		size_t _size;
	public:
		//Default constructor
		Queue() {
				_size = 0;
				_values = nullptr;
		}

		//Copy constructor
		Queue(const Queue &q) {
				if(q.size() == 0) {
						_size = 0;
						_values = nullptr;
				}
				else {
					int q_size = q.size();
					Data *q_values_copy = new Data[q_size];
					int i;
					for(i=0; i<q_size; i++) {
							*(q_values_copy+i) = *(q._values+i);
					}
					
					if(q_size == 1) {
							_values = new Data(*q_values_copy);
					}
					else {
						_values = new Data[q_size];
						for(i=0; i<q_size; i++) {
								*(_values+i) = *(q_values_copy+i);
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
		}

		//Pop from queue
		void dequeue() {
				pop_back();
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
		}

		template <class Q>
		friend std::ostream &operator<<(std::ostream &out, 
				const Queue<Q> &q);

		template <class Q>
		friend bool operator==(const Queue<Q> &left_queue, 
				const Queue<Q> &right_queue);

		template <class Q>
		friend bool operator!=(const Queue<Q> &left_queue, 
				const Queue<Q> &right_queue);
};
