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
	std::deque<T>::iterator _buf_iter;
	std::deque<T>::iterator _pos_end;
	int _front_pos=0;
public:
	std::deque<T>* data;
	cycle_queue() {
		data = new std::deque<T>(_queue_size,0);
		_pos_end = data->begin();
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
		if (_initialized == true) {
			_buf_iter = data->begin();
			_buf_iter = _buf_iter + _front_pos;
			if (_buf_iter == _pos_end) {
				_front_pos++;
				if (_front_pos == _queue_size)
					_front_pos = 0;
			}
		}
		_pos_end=data->erase(_pos_end);
		_pos_end=data->emplace(_pos_end,value);
		_pos_end++;
		_initialized = true;
		return;
	}
	T pull() {
		//T buf;
		if (_initialized == false) {
			std::cout << "queue is empty" << std::endl;
			return NULL;
		}
		_buf_iter = data->begin();
		for (int i = 0; i<=_front_pos; i++)
		_buf_iter++;
		/*if (_pos_end == (data->begin())) {
			_pos_end = data->end();
			--_pos_end;
			buf = *_pos_end;
			_pos_end = data->begin();
		}
		else {
			_buf_iter = _pos_end;
			_buf_iter=_buf_iter+_front_pos;
			buf = *_buf_iter;
		}*/
		if (_initialized == true) {
			_front_pos++;
			if (_buf_iter == _pos_end)
				_initialized = false;
			if (_front_pos == _queue_size)
				_front_pos = 0;
		}
		return *_buf_iter;
	}
	std::deque<T>::iterator begin() {
		return data->begin();
	}
	std::deque<T>::iterator end() {
		return data->end();
	}
	bool empty() {
		if (_pos_end == _front_pos)
			return true;
		else
			return false;
	}
};



#endif
