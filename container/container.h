#ifndef QCONTAINER_H
#define QCONTAINER_H

#include <iterator>
#include <initializer_list>
#include <memory>

template <typename T=int>
class qContainer {
	public:
		template <typename ValueType=T>
		class qIterator : public std::iterator<std::input_iterator_tag, ValueType>
		{
			//friend class qContainer;
			private:
				qIterator(ValueType* p);
			public:
				qIterator(const qIterator &it);
				bool operator!=(qIterator const& other) const;
				bool operator==(qIterator const& other) const;
				typename qIterator::reference operator*() const;
				qIterator& operator++();
			private:
				ValueType* p;
		};
		typedef qIterator<T> iterator;
		typedef qIterator<const T> const_iterator;

		iterator begin();
		iterator end();

		//qContainer(std::initializer_list<T> values);
		qContainer();

		const_iterator begin() const;
		const_iterator end() const;

	private:
		int* _oldest_pos;		//указатель на самый старый элемент
		const size_t container_size = 5;	//статически заданный размер контейнера
		std::unique_ptr<T[]> data;
};

#endif

