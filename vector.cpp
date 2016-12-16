#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "vector.h"

using namespace std;

Vector::Vector(void) {
	this->PSize = 0;
	this->PHead = NULL;
}

Vector::Vector(size_t size) {
	this->PHead = (Type*) calloc(size, sizeof(Type));
	this->PSize = size;
}

Vector::~Vector(void) {
	free(this->PHead);
	//cout << "Destructor_test" << endl;
}


size_t Vector::Size(void) {
	return this->PSize;
}

void Vector::Resize(size_t size) {
	this->PHead = (Type*) realloc(this->PHead, size * sizeof(Type));
	this->PSize = size;
}

Type Vector::GetValue(size_t pos) {
	Type res;
	if (pos < this->PSize) {
		res = this->PHead[pos];
	} else {
		cout << "Out of range" << endl;
	}
	return res;
}

void Vector::SetValue(Type elem, size_t pos) {
	if (pos < this->PSize) {
		this->PHead[pos] = elem;
	} else {
		cout << "Out of range" << endl;
	}
}

Type& Vector::operator[](size_t pos) {
	return this->PHead[pos];
}

const Type& Vector::operator[](size_t pos) const {
	return this->PHead[pos];
}

extern "C" Vector *new_vector() {
	return new Vector;
}
extern "C" void delete_vector(Vector *tmp) {
	delete tmp;
}
