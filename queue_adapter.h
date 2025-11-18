#ifndef _QADAPTER
#define _QADAPTER

#include <deque>
#include <iterator>

template <typename T>
class cycle_queue
{
private:
	
public:
	int _queue_size = 5;	//количество элементов в очереди очереди
	std::deque<T>* data;
	cycle_queue() {
		data = new std::deque<T>(_queue_size);
	}
	~cycle_queue() {
		
	}
private:
	//int _queue_size = 5;	//количество элементов в очереди очереди
	std::deque<T>::iterator _pos_front = data->begin();
	std::deque<T>::iterator _pos_end = data->begin();
public:
	void push(T value) {
		if (_pos_end == data->end()) {
			_pos_end = 0;
			data[_pos_end] = value;
			_pos_end++;
			return;
		}
	}
	T pull() {
		return data[_pos_front];
	}
	std::deque<T>::iterator begin() {
		return data->begin();
	}
	std::deque<T>::iterator end() {
		return data->end();
	}
};



#endif
