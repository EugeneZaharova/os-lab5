#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "vector.h"

using namespace std;

template <class T> Vector<T>::Vector(void) {
	this->PSize = 0;
	this->PHead = NULL;
}

template <class T> Vector<T>::Vector(size_t size) {
	this->PHead = (T*) calloc(size, sizeof(T));
	this->PSize = size;
}

template <class T> Vector<T>::~Vector(void) {
	free(this->PHead);
}


template <class T> size_t Vector<T>::Size(void) {
	return this->PSize;
}

template <class T> void Vector<T>::Resize(size_t size) {
	this->PHead = (T*) realloc(this->PHead, size * sizeof(T));
	this->PSize = size;
}

template <class T> T Vector<T>::GetValue(size_t pos) {
	T res;
	if (pos < this->PSize) {
		res = this->PHead[pos];
	} else {
		cout << "Out of range" << endl;
	}
	return res;
}

template <class T> void Vector<T>::SetValue(T elem, size_t pos) {
	if (pos < this->PSize) {
		this->PHead[pos] = elem;
	} else {
		cout << "Out of range" << endl;
	}
}

template <class T> T& Vector<T>::operator[](size_t pos) {
	return this->PHead[pos];
}
template <class T> const T& Vector<T>::operator[](size_t pos) const {
	return this->PHead[pos];
}

template class Vector<int>;
