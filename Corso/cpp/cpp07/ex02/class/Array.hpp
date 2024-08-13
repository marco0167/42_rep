#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdint.h>
# include <iostream>
# include <exception>

template<class T>
class Array {
	T				*_array;
	unsigned int	_size;

public:
	Array(void);
	Array(unsigned int n);
	~Array();
	Array(const Array &rhs);
	Array &operator=(const Array &rhs);
	T &operator[](unsigned int i);

	unsigned int	size() const;

	class OutOfBoundExeption: public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Out of bound!";
			}
	};
};

template<class T>
Array<T>::Array(void) : _array(new T[0]), _size(0) {}

template<class T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
}

template<class T>
Array<T>::~Array(){
	delete [] this->_array;
}

template<class T>
Array<T>::Array(const Array &rhs) {
	this->_array = new T[rhs._size];
	for (size_t i = 0; i < rhs._size; i++)
	{
		this->_array[i] = rhs._array[i];
	}

}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs) {
	if (this != &rhs) {
		delete [] this->_array;

		this->_array = new T[rhs._size];
		this->_size = rhs._size;

		for (size_t i = 0; i < rhs._size; i++)
		{
			this->_array[i] = rhs._array[i];
		}
	}

	return *this;
}

template<class T>
T &Array<T>::operator[](unsigned int i) {
	if (i < this->size())
		return this->_array[i];
	throw OutOfBoundExeption();
}

template <class T>
unsigned int	Array<T>::size() const {
	return this->_size;
}

template <class T>
std::ostream &operator<<(std::ostream &o, Array<T> &rhs) {
	for (size_t i = 0; i < rhs.size(); i++)
	{
		o << rhs[i] << " ";
	}

	return o;
}


#endif

