#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	this->len = 0;
	this->arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->len = n;
	this->arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array &ref) {
	len = ref.len;
	this->arr = new T[this->len];
	*this = ref;
}

template <typename T>
Array<T>::~Array() {delete [] this->arr;}

template <typename T>
const Array<T>& Array<T>::operator=(const Array &ref) {
	delete [] this->arr;
	this->len = ref.len;
	this->arr = new T[this->len];
	for (int i = 0; i < this->len; i++) {
		this->arr[i] = ref.arr[i];
	}
	return *this;
}

template <typename T>
int Array<T>::size() const {return this->len;}

template <typename T>
T& Array<T>::operator[](int index) {
	if (index > this->len - 1)
		throw ArrayOutOfBoundException();
	return arr[index];
}
