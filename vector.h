#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory>

typedef int Type;

class Vector {
private:
	Type *PHead;
	std::size_t PSize;

public:
	Vector(void);
	Vector(std::size_t size);
	virtual ~Vector(void);

	virtual std::size_t Size(void);
	virtual void Resize(std::size_t size);

	virtual Type GetValue(std::size_t pos);
	virtual void SetValue(Type elem, std::size_t pos);

	virtual Type& operator[](std::size_t pos);
	virtual const Type& operator[](std::size_t pos) const;
};

typedef Vector *new_vector_t(void);
typedef void delete_vector_t(Vector *tmp);

#endif
