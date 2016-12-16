#include <iostream>
#include <dlfcn.h>
#include "vector.h"

using namespace std;

int main(void) {
	void *handle = dlopen("./libvector.so", RTLD_LAZY);

	if (!handle) {
		cerr <<  dlerror() << endl;
		return 0;
	}
	new_vector_t *new_vector = (new_vector_t *) dlsym(handle, "new_vector");
	delete_vector_t *delete_vector = (delete_vector_t *) dlsym(handle, "delete_vector");

	if (!new_vector || !delete_vector) {
		cerr <<  dlerror() << endl;
		return 0;
	}


	size_t size;
	Vector *arr = new_vector();
	cout << "Arr size:" << endl;
	cin >> size;
	arr->Resize(size);
	cout << "Arr elements (" << size << ")" << endl;
	for (size_t i = 0; i < arr->Size(); i++) {
		cin >> (*arr)[i];
	}
	for (size_t i = 0; i < arr->Size(); i++) {
		cout << (*arr)[i] << ' ';
	}
	cout << endl;
	delete_vector(arr);
	dlclose(handle);
	return 0;
}
