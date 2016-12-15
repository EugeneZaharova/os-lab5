#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory>

template <class T> class Vector {
private:
	T* PHead;
	std::size_t PSize;

public:
	Vector(void);
	Vector(std::size_t size);
	~Vector(void);

	std::size_t Size(void);
	void Resize(std::size_t size);

	T GetValue(std::size_t pos);
	void SetValue(T elem, std::size_t pos);

	T& operator[](std::size_t pos);
	const T& operator[](std::size_t pos) const;
};

#endif
