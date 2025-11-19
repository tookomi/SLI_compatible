#ifndef _QADAPTER
#define _QADAPTER

#include <deque>
#include <iterator>
#include <iostream>

template <typename T>
class cycle_queue
{
private:
	int _queue_size = 5;	//количество элементов в очереди очереди
	bool _initialized = false;
	std::deque<T>::iterator _pos_front;
	std::deque<T>::iterator _pos_end;
	int _front_pos=0;
public:
	std::deque<T>* data;
	cycle_queue() {
		data = new std::deque<T>(_queue_size,0);
		_pos_end = data->end();
		_pos_front = data->begin();
	}
	~cycle_queue() {
		delete data;
	}
	int get_max_size() {
		return _queue_size;
	}
private:

public:
	void push(T value) {
		if (_pos_end == data->end())
			_pos_end = data->begin();
		else {
			_pos_end++;
			if (_pos_end == data->end())
				_pos_end = data->begin();
		}
		if (_initialized == true) { //в очередь добавлялись элементы
			if (_pos_front == _pos_end) {	// если конец догнал начало
				_pos_front++;				// сдвинуть начало
				if (_pos_front == data->end())
					_pos_front = data->begin();
			}
		}
		*_pos_end = value;
		//_pos_end++;
		_initialized = true;
		return;
	}
	T pull() {
		T buf;
		if (_initialized == false) {
			std::cout << "queue is empty" << std::endl;
			return NULL;
		}
		buf = *_pos_front;
		_pos_front++;
		if (_pos_front == data->end())
			_pos_front = data->begin();
		if (_pos_front == _pos_end)
			_initialized = false;
		return buf;
	}
	std::deque<T>::iterator begin() {
		return data->begin();
	}
	std::deque<T>::iterator end() {
		return data->end();
	}
	bool empty() {
		if (_pos_end == _pos_front)
			return true;
		else
			return false;
	}
};



#endif
