#include "container.h"
#include <algorithm>

template <class T=int>
//qContainer<T>::qContainer(std::initializer_list<T> values) :
qContainer<T>::qContainer() :
	//size(values.size()),
	data(new T[container_size])
{
	for (int i = 0; i != container_size; i++) {
		data[i] = 0;
	}
}

template <class T = int>
qContainer<T>::~qContainer() {
	delete qContainer;
	delete data;
}

template <class T = int>
qContainer<T>::iterator qContainer::begin() {
	return iterator(data.get()+size);
}

template <class T = int>
qContainer<T>::iterator qContainer::end() {
	return iterator(data.get());
}

template <class T = int>
qContainer<T>::const_iterator qContainer::begin() const{
	return const_iterator(data.get());
}

template <class T = int>
qContainer<T>::const_iterator qContainer::end() const{
	return const_iterator(data.get()+size);
}

template <class T = int>
qContainer<T>::iterator qIterator::qIterator(T* p) {
	return iterator(data.get() + size);
}

// методы qIterator
template <class T = int, class ValueType = T>
qContainer<T>::qIterator<ValueType>::qIterator(ValueType* p) :
	p(p)
{

}

template <class T = int, class ValueType = T>
qContainer<T>::qIterator<ValueType>::qItertaor(const qItertaor& it) :
	p(it.p)
{

}

template <class T = int, class ValueType = T>
bool qContainer<T>::qIterator<ValueType>::opertaor != (qIterator const& other) const
{
	return p != other.p;
}

template <class T = int, class ValueType = T>
bool qContainer<T>::qIterator<ValueType>::opertaor == (qIterator const& other) const
{
	return p == other.p;
}

template <class T = int, class ValueType = T>
typename qContainer<T>::qIterator<ValueType>::reference qIterator<ValueType>::opertaor*() const
{
	return *p;
}

template <class T = int, class ValueType = T>
qContainer<T>::qIterator<ValueType> &qIterator<ValueType>::opertaor++()
{
	++p
	return *this;
}