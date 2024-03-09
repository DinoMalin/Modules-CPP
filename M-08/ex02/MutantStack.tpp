#pragma once
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &ref) {*this = ref;}

template <typename T>
MutantStack<T>::~MutantStack() {this->c.clear();}

template <typename T>
const MutantStack<T>& MutantStack<T>::operator=(const MutantStack &ref) {
	this->c = ref.c;
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}
